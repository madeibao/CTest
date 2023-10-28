

s1 = input()
s2 = input()

class Student:
    def __init__(self,sid, cid,score1, score2) :
        self.sid = sid # 学号
        self.cid = cid # 班级号
        self.score1 = score1 #分数1
        self.score2 = score2 #分数2
    def sumScore(self):
        return self.score1+self.score2
def devide(s, courseId, students):
    for sub in s.split(";"):
        sid, score = sub.split(";")
        score = int(score)
        cid = sid[:5]
        # 如果已经记录过该学生，没有就创建对象
        if students.get(sid) is None:
            students[sid] = Student(sid, cid, -1,-1)
        if courseId==1:
            students[sid].score1 = score
        else:
            students[sid].score2 = score
def result():
    students = {} # key是学号，value是学生对象
    devide(s1, 1, students)
    devide(s2, 2, students)
    suits = list(filter(lambda stu: stu.score1 != -1 and stu.score2!=-1, students.values()))
    if len(suits)==0:
        print("NULL")
        return
    ans = {}
    for stu in suits:
        cid = stu.cid
        if ans.get(cid) is None:
            ans[cid] = []
        ans[cid].append(stu)
    tmp = list(ans.keys())
    tmp.sort() # 按照班号升序。
    for cid in tmp:
        print(cid)
        ans[cid].sort(key = lambda x:(-x.sumScore(), x.sid))
        print(";".join(map(lambda x:x.sid, ans[cid])))
result()