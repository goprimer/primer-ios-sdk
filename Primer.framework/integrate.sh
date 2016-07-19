#
#  integrate.sh - Copyright © 2016 Primer. All rights reserved.
#
#  This script strips the simulator chunks from the Primer
#  framework file whenever you do a release build.
#

if [ ${CONFIGURATION} == Release ] ; then

    # Set variables up

    PMR_EXECUTABLE_PATH="${TARGET_BUILD_DIR}/${WRAPPER_NAME}/Frameworks/Primer.framework/Primer"
    PMR_EXTRACTED_ARCHS=()

    # Extract current architectures

    for ARCH in $ARCHS ; do
        lipo -extract "$ARCH" "$PMR_EXECUTABLE_PATH" -o "$PMR_EXECUTABLE_PATH-$ARCH"
        PMR_EXTRACTED_ARCHS+=("$PMR_EXECUTABLE_PATH-$ARCH")
    done

    # Merge valid architectures

    lipo -o "$PMR_EXECUTABLE_PATH-merged" -create "${PMR_EXTRACTED_ARCHS[@]}"

    # Clean up

    rm "${PMR_EXTRACTED_ARCHS[@]}"
    rm "$PMR_EXECUTABLE_PATH"
    mv "$PMR_EXECUTABLE_PATH-merged" "$PMR_EXECUTABLE_PATH"

fi