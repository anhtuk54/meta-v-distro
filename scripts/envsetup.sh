#!/bin/sh

ECHO=$(env which echo)
BUILDDIR="../../build"
FIRST_TIME=0

cd layers/poky
if [ ! -f ${BUILDDIR}/conf/local.conf ]; then
	FIRST_TIME=1
fi

. ./oe-init-build-env ${BUILDDIR}

echo ""
echo "V targets are:"
echo "    v-image-core-boot"
echo "    v-image-core-perf"
echo "    v-image-graphics-qt5"


if [ $FIRST_TIME -eq 1 ]; then
	mkdir -p conf
	
	cp ../layers/meta-v/meta-v-distro/templates/*.conf conf/
fi
