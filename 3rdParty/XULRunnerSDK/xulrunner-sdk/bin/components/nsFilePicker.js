/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 2000
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Stuart Parmenter <pavlov@netscape.com>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

/*
 * No magic constructor behaviour, as is de rigeur for XPCOM.
 * If you must perform some initialization, and it could possibly fail (even
 * due to an out-of-memory condition), you should use an Init method, which
 * can convey failure appropriately (thrown exception in JS,
 * NS_FAILED(nsresult) return in C++).
 *
 * In JS, you can actually cheat, because a thrown exception will cause the
 * CreateInstance call to fail in turn, but not all languages are so lucky.
 * (Though ANSI C++ provides exceptions, they are verboten in Mozilla code
 * for portability reasons -- and even when you're building completely
 * platform-specific code, you can't throw across an XPCOM method boundary.)
 */


const DEBUG = false; /* set to true to enable debug messages */

const FILEPICKER_CONTRACTID     = "@mozilla.org/filepicker;1";
const FILEPICKER_CID        = Components.ID("{54ae32f8-1dd2-11b2-a209-df7c505370f8}");
const LOCAL_FILE_CONTRACTID = "@mozilla.org/file/local;1";
const APPSHELL_SERV_CONTRACTID  = "@mozilla.org/appshell/appShellService;1";
const STRBUNDLE_SERV_CONTRACTID = "@mozilla.org/intl/stringbundle;1";

const nsIAppShellService    = Components.interfaces.nsIAppShellService;
const nsILocalFile          = Components.interfaces.nsILocalFile;
const nsIFileURL            = Components.interfaces.nsIFileURL;
const nsISupports           = Components.interfaces.nsISupports;
const nsIFactory            = Components.interfaces.nsIFactory;
const nsIFilePicker         = Components.interfaces.nsIFilePicker;
const nsIInterfaceRequestor = Components.interfaces.nsIInterfaceRequestor
const nsIDOMWindow          = Components.interfaces.nsIDOMWindow;
const nsIStringBundleService = Components.interfaces.nsIStringBundleService;
const nsIWebNavigation      = Components.interfaces.nsIWebNavigation;
const nsIDocShellTreeItem   = Components.interfaces.nsIDocShellTreeItem;
const nsIBaseWindow         = Components.interfaces.nsIBaseWindow;

var   bundle                = null;
var   lastDirectory         = null;

function nsFilePicker()
{
  if (!bundle)
    bundle = srGetStrBundle("chrome://global/locale/filepicker.properties");

  /* attributes */
  this.mDefaultString = "";
  this.mFilterIndex = 0;
  this.mFilterTitles = new Array();
  this.mFilters = new Array();
  this.mDisplayDirectory = null;
  if (lastDirectory) {
    try {
      var dir = Components.classes[LOCAL_FILE_CONTRACTID].createInstance(nsILocalFile);
      dir.initWithPath(lastDirectory);
      this.mDisplayDirectory = dir;
    } catch (e) {}
  }
}

nsFilePicker.prototype = {

  /* attribute nsILocalFile displayDirectory; */
  set displayDirectory(a) {
    this.mDisplayDirectory = a &&
      a.clone().QueryInterface(nsILocalFile);
  },
  get displayDirectory()  {
    return this.mDisplayDirectory &&
           this.mDisplayDirectory.clone()
               .QueryInterface(nsILocalFile);
  },

  /* readonly attribute nsILocalFile file; */
  set file(a) { throw "readonly property"; },
  get file()  { return this.mFilesEnumerator.mFiles[0]; },

  /* readonly attribute nsISimpleEnumerator files; */
  set files(a) { throw "readonly property"; },
  get files()  { return this.mFilesEnumerator; },

  /* readonly attribute nsIURI fileURL; */
  set fileURL(a) { throw "readonly property"; },
  get fileURL()  {
    if (this.mFileURL)
      return this.mFileURL;

    if (!this.mFilesEnumerator)
      return null;

      var ioService = Components.classes["@mozilla.org/network/io-service;1"]
                    .getService(Components.interfaces.nsIIOService);

    return this.mFileURL = ioService.newFileURI(this.file);
  },

  /* attribute wstring defaultString; */
  set defaultString(a) { this.mDefaultString = a; },
  get defaultString()  { return this.mDefaultString; },

  /* attribute wstring defaultExtension */
  set defaultExtension(ext) { },
  get defaultExtension() { return ""; },

  /* attribute long filterIndex; */
  set filterIndex(a) { this.mFilterIndex = a; },
  get filterIndex() { return this.mFilterIndex; },

  /* members */
  mFilesEnumerator: undefined,
  mParentWindow: null,

  /* methods */
  init: function(parent, title, mode) {
    this.mParentWindow = parent;
    this.mTitle = title;
    this.mMode = mode;
  },

  appendFilters: function(filterMask) {
    if (filterMask & nsIFilePicker.filterHTML) {
      this.appendFilter(bundle.GetStringFromName("htmlTitle"),
                   bundle.GetStringFromName("htmlFilter"));
    }
    if (filterMask & nsIFilePicker.filterText) {
      this.appendFilter(bundle.GetStringFromName("textTitle"),
                   bundle.GetStringFromName("textFilter"));
    }
    if (filterMask & nsIFilePicker.filterImages) {
      this.appendFilter(bundle.GetStringFromName("imageTitle"),
                   "*.jpg; *.jpeg; *.gif; *.png; *.bmp; *.ico"); // XXX 528755
    }
    if (filterMask & nsIFilePicker.filterXML) {
      this.appendFilter(bundle.GetStringFromName("xmlTitle"),
                   bundle.GetStringFromName("xmlFilter"));
    }
    if (filterMask & nsIFilePicker.filterXUL) {
      this.appendFilter(bundle.GetStringFromName("xulTitle"),
                   bundle.GetStringFromName("xulFilter"));
    }
    this.mAllowURLs = !!(filterMask & nsIFilePicker.filterAllowURLs);
    if (filterMask & nsIFilePicker.filterApps) {
      // We use "..apps" as a special filter for executable files
      this.appendFilter(bundle.GetStringFromName("appsTitle"),
                        "..apps");
    }
    if (filterMask & nsIFilePicker.filterAll) {
      this.appendFilter(bundle.GetStringFromName("allTitle"),
                   bundle.GetStringFromName("allFilter"));
    }
  },

  appendFilter: function(title, extensions) {
    this.mFilterTitles.push(title);
    this.mFilters.push(extensions);
  },

  QueryInterface: function(iid) {
    if (iid.equals(nsIFilePicker) ||
        iid.equals(nsISupports))
      return this;

    throw Components.results.NS_ERROR_NO_INTERFACE;
  },

  show: function() {
    var o = new Object();
    o.title = this.mTitle;
    o.mode = this.mMode;
    o.displayDirectory = this.mDisplayDirectory;
    o.defaultString = this.mDefaultString;
    o.filterIndex = this.mFilterIndex;
    o.filters = new Object();
    o.filters.titles = this.mFilterTitles;
    o.filters.types = this.mFilters;
    o.allowURLs = this.mAllowURLs;
    o.retvals = new Object();

    var parent;
    if (this.mParentWindow) {
      parent = this.mParentWindow;
    } else if (typeof(window) == "object" && window != null) {
      parent = window;
    } else {
      try {
        var appShellService = Components.classes[APPSHELL_SERV_CONTRACTID].getService(nsIAppShellService);
        parent = appShellService.hiddenDOMWindow;
      } catch(ex) {
        debug("Can't get parent.  xpconnect hates me so we can't get one from the appShellService.\n");
        debug(ex + "\n");
      }
    }

    var parentWin = null;
    try {
      parentWin = parent.QueryInterface(nsIInterfaceRequestor)
                        .getInterface(nsIWebNavigation)
                        .QueryInterface(nsIDocShellTreeItem)
                        .treeOwner
                        .QueryInterface(nsIInterfaceRequestor)
                        .getInterface(nsIBaseWindow);
    } catch(ex) {
      dump("file picker couldn't get base window\n"+ex+"\n");
    }
    try {
      if (parentWin)
        parentWin.blurSuppression = true;
      parent.openDialog("chrome://global/content/filepicker.xul",
                        "",
                        "chrome,modal,titlebar,resizable=yes,dependent=yes",
                        o);
      if (parentWin)
        parentWin.blurSuppression = false;

      this.mFilterIndex = o.retvals.filterIndex;
      this.mFilesEnumerator = o.retvals.files;
      this.mFileURL = o.retvals.fileURL;
      lastDirectory = o.retvals.directory;
      return o.retvals.buttonStatus;
    } catch(ex) { dump("unable to open file picker\n" + ex + "\n"); }

    return null;
  }
}

if (DEBUG)
    debug = function (s) { dump("-*- filepicker: " + s + "\n"); }
else
    debug = function (s) {}

/* module foo */

var filePickerModule = new Object();

filePickerModule.registerSelf =
function (compMgr, fileSpec, location, type)
{
    debug("registering (all right -- a JavaScript module!)");
    compMgr = compMgr.QueryInterface(Components.interfaces.nsIComponentRegistrar);

    compMgr.registerFactoryLocation(FILEPICKER_CID,
                                    "FilePicker JS Component",
//@line 283 "/builds/slave/xulrunner_linux_build/build/toolkit/components/filepicker/src/nsFilePicker.js.in"
                                    "",
//@line 285 "/builds/slave/xulrunner_linux_build/build/toolkit/components/filepicker/src/nsFilePicker.js.in"
                                    fileSpec,
                                    location,
                                    type);
}

filePickerModule.getClassObject =
function (compMgr, cid, iid) {
    if (!cid.equals(FILEPICKER_CID))
        throw Components.results.NS_ERROR_NO_INTERFACE;

    if (!iid.equals(Components.interfaces.nsIFactory))
        throw Components.results.NS_ERROR_NOT_IMPLEMENTED;

    return filePickerFactory;
}

filePickerModule.canUnload =
function(compMgr)
{
    debug("Unloading component.");
    return true;
}

/* factory object */
var filePickerFactory = new Object();

filePickerFactory.createInstance =
function (outer, iid) {
    debug("CI: " + iid);
    debug("IID:" + nsIFilePicker);
    if (outer != null)
        throw Components.results.NS_ERROR_NO_AGGREGATION;

    return (new nsFilePicker()).QueryInterface(iid);
}

/* entrypoint */
function NSGetModule(compMgr, fileSpec) {
    return filePickerModule;
}



/* crap from strres.js that I want to use for string bundles since I can't include another .js file.... */

var strBundleService = null;

function srGetStrBundle(path)
{
  var strBundle = null;

  if (!strBundleService) {
    try {
      strBundleService = Components.classes[STRBUNDLE_SERV_CONTRACTID].getService(nsIStringBundleService);
    } catch (ex) {
      dump("\n--** strBundleService createInstance failed **--\n");
      return null;
    }
  }

  strBundle = strBundleService.createBundle(path);
  if (!strBundle) {
	dump("\n--** strBundle createInstance failed **--\n");
  }
  return strBundle;
}

