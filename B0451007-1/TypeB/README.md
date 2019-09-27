# LightMonitor

**该作业项目已被分出仓库单独放置。请查看本人的GitHub仓库首页寻找LightMonitor。**

网络监听程序

通过HTTP协议进行通讯

## 需求确定

Server端部署到腾讯云的一台低配主机，通过Web面板访问Server端

docker打包部署。方便演示，维护。

Server端使用Servlet技术实现，将docker Tomcat官方镜像作为docker基础镜像进行构建。

Server端如果时间充足的话，考虑使用sql储存数据，无需部署服务端，直接操作数据库文件。（练习JDBC）一张表完成，id作为主键。（未实现sql时，通过Singleton设计模式，保证id的唯一性）

考虑功能实现后，后期加上在线时长图表统计什么的的功能（用Canvas.js库实现）

客户端采用cli的方式启动，通过参数启动，传入启动所需的数据，比如说服务器的IP和Port或者是可选的usersession。usersession由服务端随机生成，作为认装。防止冒充用户（usersession可以加入文件保存到本地功能使用java.util.Properties）

## API Docs

### Register HTTP/GET

Request

| Parameter  | Description                         |
|------------|-------------------------------------|
| clientname | Set by Client cli startup parameter |

Response

| Parameter   | Description                               |
|-------------|-------------------------------------------|
| code        | StatusCode                                |
| message     | Return server message print to client cli |
| usersession | Random String by Server                   |
| id          | Sort by client first request time         |

### Heartbeat HTTP/GET

Request

| Parameter   | Description             |
|-------------|-------------------------|
| usersession | Random String by Server |

Response

| Parameter | Description                               |
|-----------|-------------------------------------------|
| code      | StatusCode                                |
| message   | Return server message print to client cli |

### Sendinfo HTTP/POST

Request

| Parameter   | Description             |
|-------------|-------------------------|
| usersession | Random String by Server |
| clientinfo  | Send info to server     |

## SQL

| Parameter    | Description                         |
|--------------|-------------------------------------|
| id           | Sort by client first request time   |
| usersession  | Random String by Server             |
| clientname   | Set by Client cli startup parameter |
| clientip     | Get From Request IP                 |
| clientinfo   | Send info to server                 |
| pkgnum       | Client Request Package Count        |
| latestonline | Lastest client active time          |
