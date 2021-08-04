// Copyright (c) 2019-2021 Intel Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "mfx_common.h"
#if defined(MFX_ENABLE_H265_VIDEO_ENCODE)

#include "hevcehw_base_rext.h"

namespace HEVCEHW
{
namespace Linux
{
namespace Base
{
class RExt
    : public HEVCEHW::Base::RExt
{
public:

    RExt(mfxU32 FeatureId)
        : HEVCEHW::Base::RExt(FeatureId)
    {
        mUpdateRecInfo =
        {
            {
                mfxU16(1 + MFX_CHROMAFORMAT_YUV420)
                , [](mfxFrameInfo& rec, mfxU16& type, bool /*bVDEnc*/)
                {
                    if (rec.BitDepthLuma == 10)
                        rec.FourCC = MFX_FOURCC_P010;
                    else
                        rec.FourCC = MFX_FOURCC_P016;
                }
            }
        };
    }

protected:
    virtual void Query1NoCaps(const FeatureBlocks& blocks, TPushQ1 Push) override;
};

} //Linux
} //Base
} //HEVCEHW
#endif //defined(MFX_ENABLE_H265_VIDEO_ENCODE)