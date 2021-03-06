//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_WIDGET_CTOASTHELPER_H__
#define __ELASTOS_DROID_WIDGET_CTOASTHELPER_H__

#include "_Elastos_Droid_Widget_CToastHelper.h"
 #include <elastos/core/Singleton.h>

using Elastos::Core::ICharSequence;
using Elastos::Droid::Content::IContext;

namespace Elastos {
namespace Droid {
namespace Widget {

CarClass(CToastHelper)
    , public Singleton
    , public IToastHelper
{
public:
    CAR_INTERFACE_DECL()

    CAR_SINGLETON_DECL();

    /**
     * Make a standard toast that just contains a text view.
     *
     * @param context  The context to use.  Usually your {@link android.app.Application}
     *                 or {@link android.app.Activity} object.
     * @param text     The text to show.  Can be formatted text.
     * @param duration How long to display the message.  Either {@link #LENGTH_SHORT} or
     *                 {@link #LENGTH_LONG}
     *
     */
    CARAPI MakeText(
        /* [in] */ IContext* context,
        /* [in] */ ICharSequence* text,
        /* [in] */ Int32 duration,
        /* [out] */ IToast** toast);

    /**
     * Make a standard toast that just contains a text view with the text from a resource.
     *
     * @param context  The context to use.  Usually your {@link android.app.Application}
     *                 or {@link android.app.Activity} object.
     * @param resId    The resource id of the string resource to use.  Can be formatted text.
     * @param duration How long to display the message.  Either {@link #LENGTH_SHORT} or
     *                 {@link #LENGTH_LONG}
     *
     * @throws Resources.NotFoundException if the resource can't be found.
     */
    CARAPI MakeText(
        /* [in] */ IContext* context,
        /* [in] */ Int32 resId,
        /* [in] */ Int32 duration,
        /* [out] */ IToast** toast);
};

} // namespace Widget
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_WIDGET_CTOASTHELPER_H__
