#search:
	def GetSelectedItem(self):
		return self.keyDict.get(self.selectedLine, 0)

#add:
	def EnableReselect(self):
		self.reselect = True

#search:
	def SelectItem(self, key):
		self.listBox.SelectItem(key)

#add:
	def EnableReselect(self):
		self.listBox.EnableReselect()

#search:
class ListBox(Window):

	TEMPORARY_PLACE = 3

	def __init__(self, layer = "UI"):
		Window.__init__(self, layer)

#add:
		self.reselect = False

#search:
	def SelectItem(self, line):

		if not self.keyDict.has_key(line):
			return

		if line == self.selectedLine:
			return

		self.selectedLine = line
		self.event(self.keyDict.get(line, 0), self.textDict.get(line, "None"))

#replace:
	def SelectItem(self, line):

		if not self.keyDict.has_key(line):
			return

		if not self.reselect:
			if line == self.selectedLine:
				return

		self.selectedLine = line
		self.event(self.keyDict.get(line, 0), self.textDict.get(line, "None"))

