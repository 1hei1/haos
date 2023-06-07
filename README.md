# haos

😄写一个小小的操作系统内核，纯属个人兴趣🤭

![](https://img.shields.io/badge/%E6%84%9F%E8%B0%A2%E5%A4%A7%E4%BD%AC%EF%BC%9A-%E8%B8%8C%E8%BA%87%E6%9C%88%E5%85%89-orange)

![Hex.pm](https://img.shields.io/hexpm/l/plug)

![Arch Linux package](https://img.shields.io/archlinux/v/core/x86_64/pacman)

![](https://img.shields.io/badge/%E7%89%88%E6%9C%AC-v1.0-green)

![](https://img.shields.io/badge/%E5%90%8D%E7%A7%B0-haox-yellow)

+ 我的思路是一点一点做，实现到网络之后开始玩64位，然后多核······

### 当下的计划👇

- [ ] 内核态

  - [ ] 任务

    - [ ] RTC抢占式任务切换(通过实时时，实现以规定的频率实现任务切换。)
    
    - [ ] 任务创建{
      这个需要实现任务地址空间的申请，并给任务添加属性(如时间片，ID，地址等等)，并将任务添加进任务队列。
    }
    
    - [ ] 任务调度{
      选择一种合适的调度算法，实现任务切换
    }
    
    - [ ] 任务销毁{
      释放内存空间，将任务从任务队列里删除。
    }
    
    - [ ] 任务动态管理{
      动态的管理任务(比如：任务内存不够时，扩展内存。任务时间片分配不合理时修改对于时间片。任务阻塞。任务锁死。等等)。
    }
    
    - [ ] 任务查找{
      通过函数实现任务队列中任务的查找。类似于htop命令
    }

- [ ] 用户态

- [ ] 扩展







