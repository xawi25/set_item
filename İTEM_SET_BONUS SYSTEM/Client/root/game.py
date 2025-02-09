#ara
	def BINARY_NEW_AddAffect(self, type, pointIdx, value, duration):
		self.affectShower.BINARY_NEW_AddAffect(type, pointIdx, value, duration)

#değiştir
	def BINARY_NEW_AddAffect(self, type, pointIdx, value, duration):
		if app.ENABLE_SET_ITEM:
			if self.affectShower:
				self.affectShower.BINARY_NEW_AddAffect(type, pointIdx, value, duration)
		else:
			self.affectShower.BINARY_NEW_AddAffect(type, pointIdx, value, duration)


#ara
	def BINARY_NEW_RemoveAffect(self, type, pointIdx):
		self.affectShower.BINARY_NEW_RemoveAffect(type, pointIdx)
#değiştir
	def BINARY_NEW_RemoveAffect(self, type, pointIdx):
		if app.ENABLE_SET_ITEM:
			if self.affectShower:
				self.affectShower.BINARY_NEW_RemoveAffect(type, pointIdx)
		else:
			self.affectShower.BINARY_NEW_RemoveAffect(type, pointIdx)