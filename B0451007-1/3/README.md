# 图书馆的图书管理程序

## 操作

### 录入书籍

录入书籍信息

### 查询书籍

- 通过id
- 通过全名
- 通过isbn
- 通过发布者
- 通过作者

### 删除书籍

通过查找书籍后，最终通过书籍id删除书籍，id一旦分配将不再复用

### 修改书籍数据

通过查找书籍后，最终通过书籍id修改书籍

## 数据库表

为了方便演示以及调试，不采用MySQL等采用网络连接的数据库，而是采用轻量的SQLite3

数据类型参见官方文档 - Datatypes In SQLite Version 3 - <https://www.sqlite.org/datatype3.html>

| id                   | full_title       | isbn          | publisher              | author      | publish_year |
|----------------------|------------------|---------------|------------------------|-------------|--------------|
| 0                    | Thinking In Java | 9783827268969 | Markt + Technik Verlag | Bruce Eckel | 2005         |
| INTERGER PRIMARY KEY | TEXT             | TEXT          | TEXT                   | TEXT        | INTEGER      |

## 参考资料

Sqlite3 官方文档 数据类型
