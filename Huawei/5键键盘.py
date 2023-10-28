

def result():
    screen = [] # 屏幕上的字母
    clip = [] # 剪切板上的字母
    isSelect = False
    for cmd in cmds:
        # 挨个搞定各个命令
        # a键在屏幕上输出一个字母a;当有字母被选择时，a和ctrl-v这两个有输出功能的键会先清空选择的字母，再进行输出
        if cmd == 1:
            if isSelect:
                screen.clear()
            # 不管清空没清空，都要加a
            screen.append('a')
            isSelect = False #记得释放。这个容易忘记。
        # 当没有选择字母时，ctrl-c和ctrl-x无效,ctrl-c将当前选择的字母复制到剪贴板, 新的内容被复制到剪贴板时会覆盖原来的内容
        elif cmd == 2:
            if isSelect:
                clip.clear()
                clip.extend(screen) # 想明白这里用的是extend
        # 当没有选择字母时，ctrl-c和ctrl-x无效, 
        # ctrl-x将当前选择的字母复制到剪贴板，并清空选择的字母;
        elif cmd == 3:
            if isSelect:
                clip.clear()
                clip.extend(screen)
                screen.clear()
                isSelect = False
        # ctrl-v将当前剪贴板里的字母输出到屏幕
        # 当有字母被选择时，a和ctrl-v这两个有输出功能的键会先清空选择的字母，再进行输出
        elif cmd == 4:
            if isSelect:
                screen.clear()
            screen.extend(clip)
            isSelect = False
        # 当屏幕上没有字母时，ctrl-a无效,ctrl-a选择当前屏幕上的所有字母
        elif cmd == 5:
            if len(screen) != 0:
                isSelect = True
    return len(screen)
result()