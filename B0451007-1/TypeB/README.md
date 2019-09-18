# LightMonitor

网络监听程序

通过HTTP协议进行通讯

## Client To Server

POST

Request

| Parameter  | Description                         |
|------------|-------------------------------------|
| clientname | Set by Client cli startup parameter |
| clientos   | By System.getProperty(os.name)      |

Response

| Parameter | Description                               |
|-----------|-------------------------------------------|
| code      | StatusCode                                |
| message   | Return server message print to client cli |

## WebPanel To Server

Get all clients status from LightMonitor Server

GET JSON(JSON Array)

| Parameter    | Description                         |
|--------------|-------------------------------------|
| clientstatus | Online / Offline                    |
| clientname   | Set by Client cli startup parameter |
| clientip     | Get From Request IP                 |
| clientos     | By System.getProperty(os.name)      |
| time         | Lastest client active time          |
