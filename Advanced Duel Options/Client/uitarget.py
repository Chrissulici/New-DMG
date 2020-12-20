#search:
		if buttonName != localeInfo.TARGET_BUTTON_FIGHT and buttonName != localeInfo.TARGET_BUTTON_AVENGE:
			button = ui.Button()
			button.SetParent(self)
			button.SetUpVisual("d:/ymir work/ui/public/small_thin_button_01.sub")
			button.SetOverVisual("d:/ymir work/ui/public/small_thin_button_02.sub")
			button.SetDownVisual("d:/ymir work/ui/public/small_thin_button_03.sub")
			button.SetText(buttonName)

#replace:
			if buttonName != localeInfo.TARGET_BUTTON_FIGHT and buttonName != localeInfo.TARGET_BUTTON_AVENGE:
				button = ui.Button()
				button.SetParent(self)
				button.SetUpVisual("d:/ymir work/ui/public/small_thin_button_01.sub")
				button.SetOverVisual("d:/ymir work/ui/public/small_thin_button_02.sub")
				button.SetDownVisual("d:/ymir work/ui/public/small_thin_button_03.sub")
				button.SetText(buttonName)
			else:
				button = ui.ComboBox()
				button.SetParent(self)
				button.InsertItem(0, "Normal")
				button.InsertItem(1, "Tactic")
				button.SetCurrentItem("Duel")
				button.SetSize(60, 20)
				button.EnableReselect()

#search:
	def OnPVP(self):
		net.SendChatPacket("/pvp %d" % (self.vid))

#replace:
	def OnPVP(self, mode = 0):
		net.SendChatPacket("/pvp %d %d" % (self.vid, mode))

