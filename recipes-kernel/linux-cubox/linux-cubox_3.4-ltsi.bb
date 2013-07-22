require linux.inc

DESCRIPTION = "Linux LTSI kernel for the CuBox device"

SRC_URI = "git://github.com/matsu/linux-stable.git;protocol=git;branch=3.4-ltsi_cubox"
SRCREV = "5c53ec13b8a2302eb7d7fde2111b6a4312969624"
S = "${WORKDIR}/git"

LINUX_VERSION ?= "3.4.39-ltsi"

COMPATIBLE_MACHINE = "cubox"

KERNEL_DEFCONFIG = "cubox_defconfig"

PARALLEL_MAKEINST = ""

PR = "r3"
PV = "${LINUX_VERSION}+git${SRCPV}"

do_configure_prepend() {
	if [ ! -f ${WORKDIR}/defconfig ]
	then
		bbnote "No ${WORKDIR}/defconfig file found - using default cubox_defconfig"
		install -m 0644 ${S}/arch/${ARCH}/configs/${KERNEL_DEFCONFIG} ${WORKDIR}/defconfig || die "No default configuration for ${MACHINE} / ${KERNEL_DEFCONFIG} available."
	fi
}

