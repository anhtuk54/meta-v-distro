require conf/distro/poky.conf

DISTRO = "v-base"
DISTRO_NAME = "V Distro Base"

SDK_VENDOR = "-vsdk"
SDK_VERSION = "devel"
SDKPATHINSTALL = "/opt/v-sdk/${SDK_VERSION}"
TARGET_VENDOR = "-v"

DISTRO_CODENAME = "A"
DISTROOVERRIDES .= ":${DISTRO_CODENAME}"

# create etc/build in the rootfs
INHERIT += "image-buildinfo"

# Log information on images and packages
INHERIT += "buildhistory"
BUILDHISTORY_COMMIT = "1"

# Locale
IMAGE_LINGUAS ?= "en-us"

# Avoid smt
ERROR_QA:remove = "version-going-backwards"

DISTRO_FEATURES:append = " pam systemd usrmerge"
DISTRO_FEATURES:remove = "sysvinit ptest"
VIRTUAL-RUNTIME_init_manager = "systemd"
PACKAGECONFIG:append:pn-systemd = " serial-getty-generator"
PACKAGECONFIG:append:pn-qemu-native = " libusb"

# Defines the root home directory as /root, as required by systemd.
ROOT_HOME = "/root"