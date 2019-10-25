import json
import sqlite3

if __name__ == '__main__':
    # 读取文件
    file = open("response.json", "r", encoding="utf-8")
    content = file.read()

    # 解析JSON
    info = json.loads(content)

    #建立数据库文件连接
    connect = sqlite3.connect("stuInfo.db")
    db_cursor = connect.cursor()

    #建表
    db_cursor.execute("CREATE TABLE student(name TEXT, gender TEXT, phone TEXT, card TEXT, colleage TEXT, mail TEXT, work TEXT);")

    for i in info['list']:
        data = (i['SQRMC'], i['XB'], i['LXDH'], i['GH'], i['SQRDWMC'], i['YXMC'], i['ZW'])
        print([data])
        db_cursor.executemany("INSERT INTO student values (?, ?, ?, ?, ?, ?, ?);", [data])
    db_cursor.close()

    connect.commit()
    connect.close()
