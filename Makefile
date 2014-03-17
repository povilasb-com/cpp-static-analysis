BUILD_DIR = build
BUILD_TYPE ?= Debug
CMAKE_DIR = $(CURDIR)

all: cmake


cmake: $(BUILD_DIR)
	cd $(BUILD_DIR); cmake \
		-D CMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		$(CMAKE_DIR) ; \
		make


test: $(BUILD_DIR)
	cd $(BUILD_DIR); cmake \
		-D CMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		$(CMAKE_DIR) ; \
		make build_test; \
		make test


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


clean:
	rm -rf $(BUILD_DIR)


.PHONY: all cmake clean
