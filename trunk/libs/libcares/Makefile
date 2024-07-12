include $(ROOTDIR)/rules.mk

PKG_NAME:=c-ares
PKG_VERSION:=1.32.1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/c-ares/c-ares/releases/download/v$(PKG_VERSION)
PKG_HASH:=63be2c4ee121faa47e9766f735b4cde750fff2c563f81c11e572d3dc6401e5e7

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

$(eval $(call BuildPackage,c-ares))

romfs:
	$(INSTALL_DIR) $(ROMFSDIR)/lib
	$(CP) $(PKG_INSTALL_DIR)/lib/libcares.so* $(ROMFSDIR)/lib/
