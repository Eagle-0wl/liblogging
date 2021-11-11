include $(TOPDIR)/rules.mk

PKG_NAME:=logtest2
PKG_RELEASE:=1
PKG_VERSION:=1.0.0

include $(INCLUDE_DIR)/package.mk

define Package/logtest2
	CATEGORY:=Base system
	TITLE:=logtest2
	DEPENDS:=+liblogging
endef

define Package/logtest2/description
	This is app used for testing liblogging library
endef

define Package/logtest2/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/logtest2 $(1)/usr/bin
endef

$(eval $(call BuildPackage,logtest2))
