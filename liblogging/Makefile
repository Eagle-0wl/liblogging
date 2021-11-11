include $(TOPDIR)/rules.mk

PKG_NAME:=liblogging
PKG_RELEASE:=1
PKG_VERSION:=1.0.0

include $(INCLUDE_DIR)/package.mk

SOURCE_DIR:=./lib

define Package/liblogging
	CATEGORY:=Libraries
	TITLE:=liblogging
	DEPENDS:=+libsqlite3
endef


define Package/liblogging/description
	This is an sample library that can be used with other programs
endef

define Build/Compile
	mkdir -p $(PKG_BUILD_DIR)
	mkdir -p $(PKG_BUILD_DIR)/lib
	cp $(SOURCE_DIR)/* $(PKG_BUILD_DIR)/lib
	cp $(SOURCE_DIR)/*.h $(PKG_BUILD_DIR)
	$(MAKE) -C $(PKG_BUILD_DIR)/lib \
		CC="$(TARGET_CC)"
	$(MAKE) -C $(PKG_BUILD_DIR) \
		CC="$(TARGET_CC)"
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lib/liblogging.so $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lib/log_lib.h $(1)/usr/include
endef

define Package/liblogging/install
	$(INSTALL_DIR) $(1)/usr/bin $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lib/liblogging.so $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/app_logging $(1)/usr/bin
endef



$(eval $(call BuildPackage,liblogging, +libsqlite3))

