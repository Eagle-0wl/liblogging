include $(TOPDIR)/rules.mk

PKG_NAME:=logtest1
PKG_RELEASE:=1
PKG_VERSION:=1.0.0

include $(INCLUDE_DIR)/package.mk

define Package/logtest1
	CATEGORY:=Base system
	TITLE:=logtest1
	DEPENDS:=+liblogging
endef

define Package/logtest1/description
	This is app used for testing liblogging library
endef

define Package/logtest1/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/logtest1 $(1)/usr/bin
endef

$(eval $(call BuildPackage,logtest1))
