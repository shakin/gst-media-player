/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/xulrunner_linux_build/build/dom/interfaces/events/nsIDOMNSUIEvent.idl
 */

#ifndef __gen_nsIDOMNSUIEvent_h__
#define __gen_nsIDOMNSUIEvent_h__


#ifndef __gen_nsIDOMNSEvent_h__
#include "nsIDOMNSEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSUIEvent */
#define NS_IDOMNSUIEVENT_IID_STR "72c9f79c-98cd-4224-a467-86b59c0a38f7"

#define NS_IDOMNSUIEVENT_IID \
  {0x72c9f79c, 0x98cd, 0x4224, \
    { 0xa4, 0x67, 0x86, 0xb5, 0x9c, 0x0a, 0x38, 0xf7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSUIEvent : public nsIDOMNSEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSUIEVENT_IID)

  enum { SCROLL_PAGE_UP = -32768 };

  enum { SCROLL_PAGE_DOWN = 32768 };

  /* readonly attribute long layerX; */
  NS_SCRIPTABLE NS_IMETHOD GetLayerX(PRInt32 *aLayerX) = 0;

  /* readonly attribute long layerY; */
  NS_SCRIPTABLE NS_IMETHOD GetLayerY(PRInt32 *aLayerY) = 0;

  /* readonly attribute long pageX; */
  NS_SCRIPTABLE NS_IMETHOD GetPageX(PRInt32 *aPageX) = 0;

  /* readonly attribute long pageY; */
  NS_SCRIPTABLE NS_IMETHOD GetPageY(PRInt32 *aPageY) = 0;

  /* readonly attribute unsigned long which; */
  NS_SCRIPTABLE NS_IMETHOD GetWhich(PRUint32 *aWhich) = 0;

  /* readonly attribute nsIDOMNode rangeParent; */
  NS_SCRIPTABLE NS_IMETHOD GetRangeParent(nsIDOMNode * *aRangeParent) = 0;

  /* readonly attribute long rangeOffset; */
  NS_SCRIPTABLE NS_IMETHOD GetRangeOffset(PRInt32 *aRangeOffset) = 0;

  /* attribute boolean cancelBubble; */
  NS_SCRIPTABLE NS_IMETHOD GetCancelBubble(PRBool *aCancelBubble) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCancelBubble(PRBool aCancelBubble) = 0;

  /* readonly attribute boolean isChar; */
  NS_SCRIPTABLE NS_IMETHOD GetIsChar(PRBool *aIsChar) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSUIEvent, NS_IDOMNSUIEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSUIEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetLayerX(PRInt32 *aLayerX); \
  NS_SCRIPTABLE NS_IMETHOD GetLayerY(PRInt32 *aLayerY); \
  NS_SCRIPTABLE NS_IMETHOD GetPageX(PRInt32 *aPageX); \
  NS_SCRIPTABLE NS_IMETHOD GetPageY(PRInt32 *aPageY); \
  NS_SCRIPTABLE NS_IMETHOD GetWhich(PRUint32 *aWhich); \
  NS_SCRIPTABLE NS_IMETHOD GetRangeParent(nsIDOMNode * *aRangeParent); \
  NS_SCRIPTABLE NS_IMETHOD GetRangeOffset(PRInt32 *aRangeOffset); \
  NS_SCRIPTABLE NS_IMETHOD GetCancelBubble(PRBool *aCancelBubble); \
  NS_SCRIPTABLE NS_IMETHOD SetCancelBubble(PRBool aCancelBubble); \
  NS_SCRIPTABLE NS_IMETHOD GetIsChar(PRBool *aIsChar); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSUIEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLayerX(PRInt32 *aLayerX) { return _to GetLayerX(aLayerX); } \
  NS_SCRIPTABLE NS_IMETHOD GetLayerY(PRInt32 *aLayerY) { return _to GetLayerY(aLayerY); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageX(PRInt32 *aPageX) { return _to GetPageX(aPageX); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageY(PRInt32 *aPageY) { return _to GetPageY(aPageY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWhich(PRUint32 *aWhich) { return _to GetWhich(aWhich); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeParent(nsIDOMNode * *aRangeParent) { return _to GetRangeParent(aRangeParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeOffset(PRInt32 *aRangeOffset) { return _to GetRangeOffset(aRangeOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetCancelBubble(PRBool *aCancelBubble) { return _to GetCancelBubble(aCancelBubble); } \
  NS_SCRIPTABLE NS_IMETHOD SetCancelBubble(PRBool aCancelBubble) { return _to SetCancelBubble(aCancelBubble); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsChar(PRBool *aIsChar) { return _to GetIsChar(aIsChar); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSUIEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLayerX(PRInt32 *aLayerX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayerX(aLayerX); } \
  NS_SCRIPTABLE NS_IMETHOD GetLayerY(PRInt32 *aLayerY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayerY(aLayerY); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageX(PRInt32 *aPageX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageX(aPageX); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageY(PRInt32 *aPageY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageY(aPageY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWhich(PRUint32 *aWhich) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhich(aWhich); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeParent(nsIDOMNode * *aRangeParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeParent(aRangeParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeOffset(PRInt32 *aRangeOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeOffset(aRangeOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetCancelBubble(PRBool *aCancelBubble) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCancelBubble(aCancelBubble); } \
  NS_SCRIPTABLE NS_IMETHOD SetCancelBubble(PRBool aCancelBubble) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCancelBubble(aCancelBubble); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsChar(PRBool *aIsChar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsChar(aIsChar); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSUIEvent : public nsIDOMNSUIEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSUIEVENT

  nsDOMNSUIEvent();

private:
  ~nsDOMNSUIEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSUIEvent, nsIDOMNSUIEvent)

nsDOMNSUIEvent::nsDOMNSUIEvent()
{
  /* member initializers and constructor code */
}

nsDOMNSUIEvent::~nsDOMNSUIEvent()
{
  /* destructor code */
}

/* readonly attribute long layerX; */
NS_IMETHODIMP nsDOMNSUIEvent::GetLayerX(PRInt32 *aLayerX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long layerY; */
NS_IMETHODIMP nsDOMNSUIEvent::GetLayerY(PRInt32 *aLayerY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageX; */
NS_IMETHODIMP nsDOMNSUIEvent::GetPageX(PRInt32 *aPageX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageY; */
NS_IMETHODIMP nsDOMNSUIEvent::GetPageY(PRInt32 *aPageY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long which; */
NS_IMETHODIMP nsDOMNSUIEvent::GetWhich(PRUint32 *aWhich)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode rangeParent; */
NS_IMETHODIMP nsDOMNSUIEvent::GetRangeParent(nsIDOMNode * *aRangeParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rangeOffset; */
NS_IMETHODIMP nsDOMNSUIEvent::GetRangeOffset(PRInt32 *aRangeOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean cancelBubble; */
NS_IMETHODIMP nsDOMNSUIEvent::GetCancelBubble(PRBool *aCancelBubble)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSUIEvent::SetCancelBubble(PRBool aCancelBubble)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isChar; */
NS_IMETHODIMP nsDOMNSUIEvent::GetIsChar(PRBool *aIsChar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSUIEvent_h__ */
