#ara
class AffectImage(ui.ExpandedImageBox):

	def __init__(self):
		ui.ExpandedImageBox.__init__(self)

		self.toolTipText = None
		self.isSkillAffect = True
		self.description = None
		self.endTime = 0
		self.affect = None
		self.isClocked = True

#altına ekle
		if app.ENABLE_SET_ITEM:
			self.tooltipItem = uiToolTip.ItemToolTip()
			self.tooltipItem.Hide()

	if app.ENABLE_SET_ITEM:
		def __del__(self):
			ui.ExpandedImageBox.__del__(self)
			del self.tooltipItem

#ara class AffectImage(ui.ExpandedImageBox): içinde 
	def SetToolTipText(self, text, x = 0, y = -19):

		if not self.toolTipText:
			textLine = ui.TextLine()
			textLine.SetParent(self)
			textLine.SetSize(0, 0)
			textLine.SetOutline()
			textLine.Hide()
			self.toolTipText = textLine

		self.toolTipText.SetText(text)
		w, h = self.toolTipText.GetTextSize()
		if localeInfo.IsARABIC():
			self.toolTipText.SetPosition(w+20, y)
		else:
			self.toolTipText.SetPosition(max(0, x + self.GetWidth()/2 - w/2), y)

#değiştir

	if app.ENABLE_SET_ITEM:
		def SetToolTipText(self, text, x = 0, y = -19, adjust_line_height = False, line_height_distance = 20):
			if not self.toolTipText:
				textLine = ui.TextLine()
				textLine.SetParent(self)
				if app.WJ_MULTI_TEXTLINE:
					textLine.SetEnterToken(True) ###
				textLine.SetSize(0, 0)
				textLine.SetOutline()
				textLine.Hide()
				self.toolTipText = textLine

				if adjust_line_height:
					line_height = self.toolTipText.GetLineHeight()
					self.toolTipText.SetLineHeight(line_height + line_height_distance)

			self.toolTipText.SetText(text)
			w, h = self.toolTipText.GetTextSize()
			self.toolTipText.SetPosition(max(0, x + self.GetWidth() / 2 - w / 2), y)
	else:
		def SetToolTipText(self, text, x = 0, y = -19):

			if not self.toolTipText:
				textLine = ui.TextLine()
				textLine.SetParent(self)
				textLine.SetSize(0, 0)
				textLine.SetOutline()
				textLine.Hide()
				self.toolTipText = textLine

			self.toolTipText.SetText(text)
			w, h = self.toolTipText.GetTextSize()
			if localeInfo.IsARABIC():
				self.toolTipText.SetPosition(w+20, y)
			else:
				self.toolTipText.SetPosition(max(0, x + self.GetWidth()/2 - w/2), y)

#ara class AffectImage(ui.ExpandedImageBox): içinde 

	def SetSkillAffectFlag(self, flag):
		self.isSkillAffect = flag

#üstüne ekle

	if app.ENABLE_SET_ITEM:
		def UpdateSetItemDescription(self, affect_type = chr.NEW_AFFECT_SET_ITEM):
			if not self.description:
				return

			if not self.tooltipItem:
				toolTip = self.description
			else:
				toolTip = self.description
				toolTip += "\\n"
				setitem_effect_dict = player.GetSetItemEffect(affect_type)

				if type(setitem_effect_dict) is dict:
					if len(setitem_effect_dict) > 0:
						for k in setitem_effect_dict.keys():
							
							toolTip += self.tooltipItem.GetAffectString(k, setitem_effect_dict[k])
							toolTip += "\\n"

			self.SetToolTipText(toolTip, 0, 30, True, 15)

#ara class AffectImage(ui.ExpandedImageBox): içinde
	def OnMouseOverIn(self):
		if self.toolTipText:
			self.toolTipText.Show()

#değiştir
	def OnMouseOverIn(self):
		if self.toolTipText:
			if app.ENABLE_SET_ITEM and self.affect == chr.NEW_AFFECT_SET_ITEM:
				self.UpdateSetItemDescription()
			self.toolTipText.Show()

#ara
	if app.ENABLE_DRAGON_SOUL_SYSTEM:
		AFFECT_DATA_DICT[chr.NEW_AFFECT_DRAGON_SOUL_DECK1] = (localeInfo.TOOLTIP_DRAGON_SOUL_DECK1, "d:/ymir work/ui/dragonsoul/buff_ds_sky1.tga")
		AFFECT_DATA_DICT[chr.NEW_AFFECT_DRAGON_SOUL_DECK2] = (localeInfo.TOOLTIP_DRAGON_SOUL_DECK2, "d:/ymir work/ui/dragonsoul/buff_ds_land1.tga")

#altına ekle
	if app.ENABLE_SET_ITEM:
		AFFECT_DATA_DICT[chr.NEW_AFFECT_SET_ITEM] = (localeInfo.TOOLTIP_SET_ITEM, "d:/ymir work/ui/skill/common/affect/set_bonus.sub")


#ara
	def __init__(self):
		ui.Window.__init__(self)

		self.serverPlayTime=0
		self.clientPlayTime=0

		self.lastUpdateTime=0
		self.affectImageDict={}
		self.horseImage=None
		self.lovePointImage=None

#altına ekle
		if app.ENABLE_SET_ITEM:
			self.SetItemAffectCheck()

#ara
	def ClearAllAffects(self):

#üstüne ekle
	def __del__(self):
		ui.Window.__del__(self)

	if app.ENABLE_SET_ITEM:
		def SetItemAffectCheck(self):
			if player.EmptySetItemEffect(chr.NEW_AFFECT_SET_ITEM):
				self.BINARY_NEW_RemoveAffect(chr.NEW_AFFECT_SET_ITEM, 0)
			else:
				self.BINARY_NEW_RemoveAffect(chr.NEW_AFFECT_SET_ITEM, 0)
				self.BINARY_NEW_AddAffect(chr.NEW_AFFECT_SET_ITEM, 0, 0, self.INFINITE_AFFECT_DURATION)

#ara

	def BINARY_NEW_AddAffect(self, type, pointIdx, value, duration):

#altında bul 
		if self.affectImageDict.has_key(affect):
			return
#değiştir
		if self.affectImageDict.has_key(affect):
			if app.ENABLE_SET_ITEM and affect == chr.NEW_AFFECT_SET_ITEM:
				self.affectImageDict[affect].UpdateSetItemDescription(affect)
			return

#ara

			elif affect == chr.NEW_AFFECT_AUTO_SP_RECOVERY or affect == chr.NEW_AFFECT_AUTO_HP_RECOVERY:
				image.UpdateAutoPotionDescription()

#altına ekle
			elif app.ENABLE_SET_ITEM and affect == chr.NEW_AFFECT_SET_ITEM:
				image.SetClock(False)
				image.UpdateSetItemDescription(affect)

#ara
	def OnUpdate(self):
#altında bul
						image.UpdateAutoPotionDescription()
						continue

#altına ekle
					if app.ENABLE_SET_ITEM:
						if image.GetAffect() == chr.NEW_AFFECT_SET_ITEM:
							continue