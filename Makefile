CP_RF := cp -rf
MKDIR_P := mkdir -p
RM_RF := rm -rf

# Architecture Specific Configuration
ifeq ($(ARCH),windows)
  # Windows Config
  CC := x86_64-w64-mingw32-g++
  LNFLAGS := -Wl,-O1
else
  # *nix Config
  CC := g++

  ifeq ($(ARCH),linux)
    # Linux Config
    LNFLAGS := -Wl,-O1
  else
    # OSX Config
    ARCH := osx
  endif
endif

# Add -g for additional debugging options in 'gdb'
CFLAGS := -c -std=c++1y -Wextra -Wno-unused-variable -Wno-narrowing

BUILD_DIR := bin
EXEC_GENERIC := $(BUILD_DIR)/FIST
EXEC_OS := $(EXEC_GENERIC)-$(ARCH).a

INCLUDES := -Iinclude

SRC_DIR := src
SRC_FILE_DIRS := $(SRC_DIR) \
                 $(SRC_DIR)/Foundation \
                 $(SRC_DIR)/Parser \
                 $(SRC_DIR)/Persistence
SOURCES := $(foreach dir,$(SRC_FILE_DIRS),$(wildcard $(dir)/*.cc))

OBJ_DIR := $(BUILD_DIR)/obj/$(ARCH)
OBJECTS := $(patsubst %.cc,$(OBJ_DIR)/%.o,$(SOURCES))

# Phony targets

all: linux windows

.PHONY: all clean cleansingle deepclean executable linux osx windows

clean:
	@$(MAKE) cleansingle ARCH=linux
	@$(MAKE) cleansingle ARCH=osx
	@$(MAKE) cleansingle ARCH=windows

cleansingle:
	$(RM) $(OBJECTS) $(EXEC_OS)*

deepclean: clean
	$(RM_RF) $(BUILD_DIR)

executable: $(EXEC_OS)

linux:
	@$(MAKE) executable ARCH=linux

osx:
	@$(MAKE) executable ARCH=osx

windows:
	@$(MAKE) executable ARCH=windows

# File targets

$(EXEC_OS): $(OBJECTS)
	ar rvs $@ $(OBJECTS)

$(OBJ_DIR)/%.o: %.cc
	@$(MKDIR_P) $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
