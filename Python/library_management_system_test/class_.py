#!/usr/bin/python3
#-*-UTF-8-*-

#基类 书 有的属性:书名,离馆时间,归还时间,书籍编号
class Book:
    def __init__(self, book_name, leave_time, return_time, book_number):
        self.book_name = book_name
        self.leave_time = leave_time
        self.return_time = return_time
        self.book_number = book_number
        self.root_change = []

    def getBookName(self):
        return self.book_name

    def getLeaveTime(self):
        return self.leave_time

    def getReturnTime(self):
        return self.return_time

    def getBookNumber(self):
        return self.book_number

    def getBorrowTIme(self):
        return (self.return_time - self.leave_time)

    def getRootChange(self):
        return self.root_change
    
    def setRootChange(self, name):
        user_borrow_time = self.getBorrowTIme()
        user_borrow = [{'name' : name, 'time' : user_borrow_time}]
        self.root_change.extend(user_borrow)

    def setBookName(self,book_name):
        self.book_name = book_name

    def setMartk(self,mark):
        self.mark = mark
        
    def setLeaveTime(self,leave_time):
        self.leave_time = leave_time

    def setReturnTime(self,return_time):
        self.return_time = return_time

    def setBookNumber(self,book_number):
        self.book_number = book_number
    '''
    def __str__(self):
        return str({"book_name": self.book_name, "leave_time": self.leave_time})
    '''
    

#派生类 教辅类书籍 私有属性是辅导的科目
class TeachingAidsBook(Book):  
    def __init__(self,subject, book_name, leave_time, return_time, book_number):
        Book.__init__(self, book_name, leave_time, return_time, book_number)
        self.__subject = subject
        self.mark = 'TeachingAidsBook'
    def getPrivate(self):
        return self.__subject

    def setPrivate(self, subject):
        self.__subject = subject


#派生类 科学类,私有属性是研究方向
class ScienceBook(Book):  
    def __init__(self, research_direction, book_name, leave_time, return_time, book_number):
        Book.__init__(self, book_name, leave_time, return_time, book_number)
        self.__research_direction = research_direction
        self.mark = 'ScienceBook'
    def getPrivate(self):
        return self.__research_direction

    def setPrivate(self, research_direction):
        self.__research_direction = research_direction


#派生类 科普类书籍,它的私有属性是科普对象(物品)
class PopularScienceBook(Book):
    def __init__(self, goods, book_name, leave_time, return_time, book_number):
        Book.__init__(self, book_name, leave_time, return_time, book_number)
        self.__goods = goods
        self.mark = 'PopularScienceBook'

    def getPrivate(self):
        return self.__goods

    def setPrivate(self, goods):
        self.__goods = goods
    

#派生类 小说 它的私有属性是,分区类型
class NovelBook(Book):
    def __init__(self, novel_type, book_name, leave_time, return_time, book_number):
        Book.__init__(self, book_name, leave_time, return_time, book_number)
        self.__novel_type = novel_type
        self.mark = 'NovelBook'

    def getPrivate(self):
        return self.__novel_type

    def setPrivate(self, novel_type):
        self.__novel_type = novel_type


#派生类 生活类 他的私有属性是用途..
class LifeBook(Book):
    def __init__(self, purpose, book_name, leave_time, return_time, book_number):
        Book.__init__(self, book_name, leave_time, return_time, book_number)
        self.__purpose = purpose
        self.mark = 'LifeBook'

    def getPrivate(self):
        return self.__purpose
        
    def setPrivate(self, purpose):
        self.__purpose = purpose
