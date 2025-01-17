/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/xulrunner_linux_build/build/netwerk/protocol/file/public/nsIFileProtocolHandler.idl
 */

#ifndef __gen_nsIFileProtocolHandler_h__
#define __gen_nsIFileProtocolHandler_h__


#ifndef __gen_nsIProtocolHandler_h__
#include "nsIProtocolHandler.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsIFileProtocolHandler */
#define NS_IFILEPROTOCOLHANDLER_IID_STR "1fb25bd5-4354-4dcd-8d97-621b7b3ed2e4"

#define NS_IFILEPROTOCOLHANDLER_IID \
  {0x1fb25bd5, 0x4354, 0x4dcd, \
    { 0x8d, 0x97, 0x62, 0x1b, 0x7b, 0x3e, 0xd2, 0xe4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFileProtocolHandler : public nsIProtocolHandler {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILEPROTOCOLHANDLER_IID)

  /**
     * This method constructs a new file URI 
     *
     * @param aFile nsIFile
     * @return reference to a new nsIURI object
     */
  /* nsIURI newFileURI (in nsIFile aFile); */
  NS_SCRIPTABLE NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
     * Converts the nsIFile to the corresponding URL string.  NOTE: under
     * some platforms this is a lossy conversion (e.g., Mac Carbon build).
     * If the nsIFile is a local file, then the result will be a file://
     * URL string.
     *
     * The resulting string may contain URL-escaped characters.
     * NOTE: Callers should use getURLSpecFromActualFile or
     * getURLSpecFromDirFile if possible, for performance reasons.
     */
  /* AUTF8String getURLSpecFromFile (in nsIFile file); */
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromFile(nsIFile *file, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Converts the nsIFile to the corresponding URL string. Should
     * only be called on files which are not directories. Otherwise
     * identical to getURLSpecFromFile, but is usually more efficient.
     * WARNING: This restriction may not be enforced at runtime! 
     */
  /* AUTF8String getURLSpecFromActualFile (in nsIFile file); */
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromActualFile(nsIFile *file, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Converts the nsIFile to the corresponding URL string. Should
     * only be called on files which are directories. Otherwise
     * identical to getURLSpecFromFile, but is usually more efficient.
     * WARNING: This restriction may not be enforced at runtime! 
     */
  /* AUTF8String getURLSpecFromDir (in nsIFile file); */
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromDir(nsIFile *file, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Converts the URL string into the corresponding nsIFile if possible.
     * A local file will be created if the URL string begins with file://.
     */
  /* nsIFile getFileFromURLSpec (in AUTF8String url); */
  NS_SCRIPTABLE NS_IMETHOD GetFileFromURLSpec(const nsACString & url, nsIFile **_retval NS_OUTPARAM) = 0;

  /**
     * Takes a local file and tries to interpret it as an internet shortcut
     * (e.g. .url files on windows).
     * @param file The local file to read
     * @return The URI the file refers to
     *
     * @throw NS_ERROR_NOT_AVAILABLE if the OS does not support such files.
     * @throw NS_ERROR_NOT_AVAILABLE if this file is not an internet shortcut.
     */
  /* nsIURI readURLFile (in nsIFile file); */
  NS_SCRIPTABLE NS_IMETHOD ReadURLFile(nsIFile *file, nsIURI **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFileProtocolHandler, NS_IFILEPROTOCOLHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILEPROTOCOLHANDLER \
  NS_SCRIPTABLE NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromFile(nsIFile *file, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromActualFile(nsIFile *file, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromDir(nsIFile *file, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFileFromURLSpec(const nsACString & url, nsIFile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReadURLFile(nsIFile *file, nsIURI **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILEPROTOCOLHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI **_retval NS_OUTPARAM) { return _to NewFileURI(aFile, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromFile(nsIFile *file, nsACString & _retval NS_OUTPARAM) { return _to GetURLSpecFromFile(file, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromActualFile(nsIFile *file, nsACString & _retval NS_OUTPARAM) { return _to GetURLSpecFromActualFile(file, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromDir(nsIFile *file, nsACString & _retval NS_OUTPARAM) { return _to GetURLSpecFromDir(file, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileFromURLSpec(const nsACString & url, nsIFile **_retval NS_OUTPARAM) { return _to GetFileFromURLSpec(url, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadURLFile(nsIFile *file, nsIURI **_retval NS_OUTPARAM) { return _to ReadURLFile(file, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILEPROTOCOLHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewFileURI(aFile, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromFile(nsIFile *file, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURLSpecFromFile(file, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromActualFile(nsIFile *file, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURLSpecFromActualFile(file, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetURLSpecFromDir(nsIFile *file, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURLSpecFromDir(file, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileFromURLSpec(const nsACString & url, nsIFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileFromURLSpec(url, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadURLFile(nsIFile *file, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadURLFile(file, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFileProtocolHandler : public nsIFileProtocolHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILEPROTOCOLHANDLER

  nsFileProtocolHandler();

private:
  ~nsFileProtocolHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFileProtocolHandler, nsIFileProtocolHandler)

nsFileProtocolHandler::nsFileProtocolHandler()
{
  /* member initializers and constructor code */
}

nsFileProtocolHandler::~nsFileProtocolHandler()
{
  /* destructor code */
}

/* nsIURI newFileURI (in nsIFile aFile); */
NS_IMETHODIMP nsFileProtocolHandler::NewFileURI(nsIFile *aFile, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getURLSpecFromFile (in nsIFile file); */
NS_IMETHODIMP nsFileProtocolHandler::GetURLSpecFromFile(nsIFile *file, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getURLSpecFromActualFile (in nsIFile file); */
NS_IMETHODIMP nsFileProtocolHandler::GetURLSpecFromActualFile(nsIFile *file, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getURLSpecFromDir (in nsIFile file); */
NS_IMETHODIMP nsFileProtocolHandler::GetURLSpecFromDir(nsIFile *file, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile getFileFromURLSpec (in AUTF8String url); */
NS_IMETHODIMP nsFileProtocolHandler::GetFileFromURLSpec(const nsACString & url, nsIFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI readURLFile (in nsIFile file); */
NS_IMETHODIMP nsFileProtocolHandler::ReadURLFile(nsIFile *file, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFileProtocolHandler_h__ */
