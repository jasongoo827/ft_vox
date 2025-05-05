# 기본 설정
BUILD_DIR := build
EXECUTABLE := ft_minecraft
SRC_DIR := src
CPU_CORES := $(shell sysctl -n hw.logicalcpu)

# 소스 파일 목록 (변경 감지용)
SOURCES := $(shell find $(SRC_DIR) -type f \( -name '*.cpp' -o -name '*.h' \))

# 기본은 Release
BUILD_TYPE ?= Release

# 공통 타겟
all: release

# Debug 타겟
debug:
	$(MAKE) BUILD_TYPE=Debug build

# Release 타겟
release:
	$(MAKE) BUILD_TYPE=Release build

# 실제 빌드 처리
build:
	@echo "[CMAKE] Generating build files in $(BUILD_DIR)/$(BUILD_TYPE) with type $(BUILD_TYPE)..."
	@mkdir -p $(BUILD_DIR)/$(BUILD_TYPE)
	cmake -S . -B $(BUILD_DIR)/$(BUILD_TYPE) -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)
	cmake --build $(BUILD_DIR)/$(BUILD_TYPE) --parallel $(CPU_CORES)

# 실행
run: release
	@echo "[RUN] Running..."
	@./$(BUILD_DIR)/Release/src/$(EXECUTABLE)

rdebug: debug
	@echo "[RUN] Running..."
	@./$(BUILD_DIR)/Debug/src/$(EXECUTABLE)

# 정리
clean:
	@echo "[CLEAN] Removing build directory..."
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all debug release build run clean fclean re
