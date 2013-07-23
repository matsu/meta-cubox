IMAGE_FEATURES += "package-management ssh-server-dropbear x11-base"

LICENSE = "MIT"

inherit core-image

IMAGE_INSTALL += " \
        gstreamer \
    gst-meta-base \
    gst-meta-x11-base \
    gst-meta-audio \
    gst-meta-debug \
    gst-meta-video \
	marvell-libgfx \
	marvell-libbmm \
	marvell-libvmeta \
        gst-plugins-marvell \
        gst-plugins-bmmxv \
	alsa-lib \
	alsa-conf \
	alsa-utils \
"

IMAGE_LINGUAS = " "


copy_uimage_and_bootscript() {
	mkdir -p "${IMAGE_ROOTFS}/boot"
	cp "${DEPLOY_DIR_IMAGE}/${KERNEL_IMAGETYPE}-${MACHINE}.bin" "${IMAGE_ROOTFS}/boot/${KERNEL_IMAGETYPE}"
	mkimage -A arm -O linux -a 0 -e 0 -T script -C none -n "CuBox boot script for SD card" -d "${FILE_DIRNAME}/../../conf/boot/boot.script" "${IMAGE_ROOTFS}/boot/boot.scr"
}


ROOTFS_POSTPROCESS_COMMAND += "copy_uimage_and_bootscript ; "

