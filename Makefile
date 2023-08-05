PROJECT_ROOT=$(PWD)
SRC_DIR = $(PROJECT_ROOT)
BUILD_DIR = $(PROJECT_ROOT)/build

run: build
	${BUILD_DIR}/cebal/cebal

clean:
	rm -rf build || true

build:
	cmake \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-S ${SRC_DIR} \
		-B ${BUILD_DIR}
	make -C ${BUILD_DIR}

rebuild: clean build

fmt:
	find cebal -iname *.h -o -iname *.cpp | xargs clang-format -i


.PHONY: clean build rebuild
