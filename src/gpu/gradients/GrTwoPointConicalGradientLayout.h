/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrTwoPointConicalGradientLayout.fp; do not modify.
 **************************************************************************************************/
#ifndef GrTwoPointConicalGradientLayout_DEFINED
#define GrTwoPointConicalGradientLayout_DEFINED
#include "SkTypes.h"

#include "SkTwoPointConicalGradient.h"
#include "GrFragmentProcessor.h"
#include "GrCoordTransform.h"
class GrTwoPointConicalGradientLayout : public GrFragmentProcessor {
public:
    enum class Type { kFocal = 2, kRadial = 0, kStrip = 1 };
    const SkMatrix44& gradientMatrix() const { return fGradientMatrix; }
    const Type& type() const { return fType; }
    bool isRadiusIncreasing() const { return fIsRadiusIncreasing; }
    bool isFocalOnCircle() const { return fIsFocalOnCircle; }
    bool isWellBehaved() const { return fIsWellBehaved; }
    bool isSwapped() const { return fIsSwapped; }
    bool isNativelyFocal() const { return fIsNativelyFocal; }
    const SkPoint& focalParams() const { return fFocalParams; }

    static std::unique_ptr<GrFragmentProcessor> Make(const SkTwoPointConicalGradient& gradient,
                                                     const GrFPArgs& args);
    GrTwoPointConicalGradientLayout(const GrTwoPointConicalGradientLayout& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "TwoPointConicalGradientLayout"; }

private:
    GrTwoPointConicalGradientLayout(SkMatrix44 gradientMatrix,
                                    Type type,
                                    bool isRadiusIncreasing,
                                    bool isFocalOnCircle,
                                    bool isWellBehaved,
                                    bool isSwapped,
                                    bool isNativelyFocal,
                                    SkPoint focalParams)
            : INHERITED(kGrTwoPointConicalGradientLayout_ClassID, kNone_OptimizationFlags)
            , fGradientMatrix(gradientMatrix)
            , fType(type)
            , fIsRadiusIncreasing(isRadiusIncreasing)
            , fIsFocalOnCircle(isFocalOnCircle)
            , fIsWellBehaved(isWellBehaved)
            , fIsSwapped(isSwapped)
            , fIsNativelyFocal(isNativelyFocal)
            , fFocalParams(focalParams)
            , fCoordTransform0(gradientMatrix) {
        this->addCoordTransform(&fCoordTransform0);
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    SkMatrix44 fGradientMatrix;
    Type fType;
    bool fIsRadiusIncreasing;
    bool fIsFocalOnCircle;
    bool fIsWellBehaved;
    bool fIsSwapped;
    bool fIsNativelyFocal;
    SkPoint fFocalParams;
    GrCoordTransform fCoordTransform0;
    typedef GrFragmentProcessor INHERITED;
};
#endif
