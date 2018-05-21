class Rect:
    def __init__(self, x, y, width, height):
        self.x = x
        self.y = y
        self.width = width
        self.height = height

    def canonicalize(self):
        if self.width < 0:
            self.x = self.x + self.width
            self.width = -self.width

        if self.height < 0:
            self.y = self.y + self.height
            self.height = -self.height

    def print_rectangle(self):
        self.canonicalize()
        if self.width == 0 & self.height == 0:
            print('<empty>')
        else:
            print('({}, {}) to ({}, {})'.format(
                self.x, self.y, self.x + self.width, self.y + self.height))

    def intersection(self, rect):
        self.canonicalize()
        if (self.x >= rect.x + rect.width or self.x + self.width <= rect.x or
            self.y >= rect.y + rect.height or self.y + self.height <= rect.y):
            self.width = 0
            self.height = 0
        else:
            right = min(self.x + self.width, rect.x + rect.width)
            top = min(self.y + self.height, rect.y + rect.height)
            self.x = max(self.x, rect.x)
            self.y = max(self.y, rect.y)
            self.width = right - self.x
            self.height = top - self.y

    def __repr__(self):
        return '[{}, {}, {}, {}]'.format(
            self.x, self.y, self.width, self.height)


rect_1 = Rect(2, 3, 5, 6)
rect_1.canonicalize()
rect_2 = Rect(4, 5, -5, -7)
rect_2.canonicalize()
rect_3 = Rect(-2, 7, 7, -10)
rect_3.canonicalize()
rect_4 = Rect(0, 7, -4, 2)
rect_4.canonicalize()

rect_4.intersection(rect_3)
rect_4.print_rectangle()
