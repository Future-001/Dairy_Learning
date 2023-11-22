# **VMware的应用：**

快照：

克隆：

![](https://github.com/Future-001/Dairy_Learning/blob/Linux/Linux%E6%96%87%E4%BB%B6.png)

## **系统分区：**

------

**Windows：分区，分配盘符，格式化**

> **Linux：分区，分配盘符（挂载），给每个设备建立一个文件，格式化使用**
>
> 分区：将大硬盘分为小的逻辑分区
>
> 格式化：写入文件系统
>
> 分区设备文件名；给每个分区定义设备文件名
>
> 挂载：给每个分区分配挂载点
>
> <img src="https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/image-20231121152950046.png" alt="image-20231121152950046" style="zoom:33%;" /><img src="https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/image-20231121153013686.png" alt="image-20231121153013686" style="zoom:33%;" /><img src="https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/image-20231121153027796.png" alt="image-20231121153027796" style="zoom:33%;" />
>
> **IDE接口     								 SCSI    							SATA**

/dev/sd[a....]    分区中的编号1~4 只能给主分区或者扩展分区使用，即使主分区或扩展分区没有使用到4，在扩展分区中的子分区（逻辑分区）不能使用1~4

![image-20231121153538727](MD_Picture/image-20231121153538727.png)

如上图：sdb5,sdb6... 不会将其识别为1~4

逻辑分区永远都是从5开始的

### **挂载：**

#### 必须分区：

- ​		/              (根分区)

- ​		swap分区（交换分区，内存的两倍，不超过2G)

#### 推荐分区：

- ​		/boot（启动分区，200MB,免得根分区满了，难以启动)

![image-20231121154452919](https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/image-20231121154452919.png)

- [ ] 

F2 进入BIOS，以前的需要进行 利用光盘启动。（真实机器 上需要修改一下）

swap分区，是没有挂载点的，是给操作系统自己调用的，无法分配挂载点。（直接就是swap类型）

操作系统只能分配四个主分区，第四个主分区会自动被分配为扩展分区，在其中进行逻辑分区。

#### 安装类型：

------

![image-20231121160159775](https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/image-20231121160159775.png)

做的越多，错的可能更多。================》   稳定和安全

![image-20231121160645140](https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/image-20231121160645140.png)

Kickstart.cfg:  记录安装过程，方便大规模的服务器安装

## 远程登陆管理工具

------



| **桥接：**                               | NAt                          | Host-ONLY           |
| ---------------------------------------- | ---------------------------- | ------------------- |
| 真实的网卡（本地有线+无线连接）          | VMware Net8虚拟网卡          | VMware Net1虚拟网卡 |
| 当前真实计算机进行通信                   | 与真实主机进行通信           | 与真实主机进行通信  |
| 和同网段计算机进行通信                   | /                            | /                   |
| （但是会占用真实**网段**IP）能访问互联网 | 使用共享的主机IP，访问互联网 | /                   |

要与主机进行通信：查看网络属性是否在同一网段之下。

ifconfig  (   winsdows是 ipconfig)  ===>   现在改了   ip addr

if  ====>  interface 

### 网络配置：

Linux中一切皆文件，那么， ipconfig xxx（给网络起个名字,一般从 xxx0开始)  192.168.12.x  只要和主机在一个网段（没有网线的话就是自动获得的）

--------》  这个只是临时设置，需要修改配置文件才是永远的，一切皆文件，硬件也是文件

桥接有两个 有线&& 无线：可能是 VMware 中虚拟环境配置，需要自动桥接成了无线或有线，选择其中一个。

![image-20231121164028176](https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/image-20231121164028176.png)

### 快速链接工具：

[SecurGRT]: https://zhuanlan.zhihu.com/p/163089404

有的Linux禁止使用root直接登录，需要利用普通用户登录。

![image-20231121170636915](https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/image-20231121170636915.png)

![](https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/image-20231121164814748.png)

### Winscp:

windows和Linux之间进行文档的拷贝，登录同上方法。

### linux:注意事项

1. 大小写敏感
2. 后缀名，Linux不需要后缀名（扩展名），一切皆文件（硬件也是）
3. 但是自己也可以扩展名（主要让管理员区分)
4. ![image-20231121212809725](https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/image-20231121212809725.png)
5. Linux的所有存储设备必须挂载后使用（包括硬盘，U盘。。。）
6. ![](https://github.com/Future-001/Dairy_Learning/blob/Linux/MD_Picture/Linux文件.png)

### 服务器的注意事项：

​			不允许关机，只能重启，重启时应该关闭服务。不要再服务器访问高峰运行高负载命令。远程配置防火墙时不要把自己提出服务器。密码规范，定期更新，合理分配权限，定期备份。

## 遇到的问题：

------

1. ping不通： 现在ifconfig 不用了，使用 ip addr 
2. 现在好像不用自己配置IP了
3. 修改命令： ip addr add ip地址 dev ens33
4. 端口号

> ~~~word
> ●检查SSH软件包是否已安装：
> rpm -q openssh-server
> 如果openssh-server软件包已安装，将会显示软件包的版本信息。
> ●如果未安装，你可以通过以下命令来安装它：
> sudo yum install openssh-server
> 
> ●检查SSH服务状态：注意端口号
> systemctl status sshd
> ●如果SSH服务已经安装并启动，你将会看到类似以下的输出：
> 
> ● sshd.service - OpenSSH server daemon
>   Loaded: loaded (/usr/lib/systemd/system/sshd.service; enabled; vendor preset: enabled)
>   Active: active (running) since [日期时间]
>     Docs: man:sshd(8)
>         man:sshd_config(5)
> Main PID: [PID号] (sshd)
>   CGroup: /system.slice/sshd.service
>           └─[PID号] /usr/sbin/sshd -D
>           
> ●如果SSH服务未安装或者未启动，你可以通过以下命令来安装并启动它：
> 
> sudo yum install openssh-server
> sudo systemctl start sshd
> sudo systemctl enable sshd
> ~~~
>

