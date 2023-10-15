# Отчет по лабораторной работе № 2
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Татаркин Иван Владимирович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Операции в терминале Linux
2. **Цель работы**: Изучение основных команд и операций в терминале Linux
3. **Задание**:
- Опробовать следующие команды:
    - who
    - pwd
    - ls
    - cd
    - cp
    - mv
    - rm
    - cat
    - ps
    - tail
    - head
    - grep
    - history
    - mkdir
    - rmdir
    - sudo
    - echo
    - ssh
    - scp
    - ssh-keygen
    - ssh-copy-id
- Использовать основные команды
- Сохранить листинг в файл
- Заархивировать
- Отправить на удаленную машину, там разархивировать
- Скачать разархивированный файл к себе на машину
4. **Идея, метод, алгоритм решения задачи**: 
Для выполнения данной лабораторной работы будем последовательно выполнять каждую из предложенных команд и операций. Для архивации файлов будем использовать команду `tar`. Для передачи файлов на удаленную машину и обратно - команду `scp`. Для работы с SSH-ключами - команды `ssh-keygen` и `ssh-copy-id`.
5. **Сценарий выполнения работы**: 
- Опробовать команды и операции, записывая результаты выполнения в файл `listing.md`
- Заархивировать файл `listing.md` с помощью команды `tar`
```bash
tar -czvf listing.tar.gz listing.md
```
- Отправить архив на удаленную машину с использованием `scp`
```bash
scp listing.tar.gz t_grigoriev@ip:~
```
- На удаленной машине разархивировать файл
```bash
tar -xzvf listing.tar.gz
```
- Скачать разархивированный файл обратно на локальную машину с использованием `scp`
```bash
scp t_grigoriev@ip:~/listing.md ~/"Рабочий стол"
```
6. **Протокол**: 
```bash
ivan@ivan-ASUS:~$ who
ivan     tty2         2023-10-15 13:31 (tty2)
ivan@ivan-ASUS:~$ pwd
/home/ivan
ivan@ivan-ASUS:~$ ls
 fff              report.md       yandex_pytjon_labs   Изображения     Шаблоны
 Inf_Labs         report.md.pub   Видео                Музыка
 listing.tar.gz   snap            Документы            Общедоступные
 my_repository    tatarkin_labs   Загрузки            'Рабочий стол'
ivan@ivan-ASUS:~$ ls
 fff              report.md       Видео       Изображения    'Рабочий стол'
 Inf_Labs         report.md.pub   Документы   Музыка          Шаблоны
 listing.tar.gz   snap            Загрузки    Общедоступные
ivan@ivan-ASUS:~$ cp report.md Inf_labs
cp: не удалось выполнить stat для 'report.md': Нет такого файла или каталога
ivan@ivan-ASUS:~$ cp fff Inf_labs
cp: не указан -r; пропускается каталог 'fff'
ivan@ivan-ASUS:~$ ls
 fff              snap        Загрузки      Общедоступные
 Inf_Labs         Видео       Изображения  'Рабочий стол'
 listing.tar.gz   Документы   Музыка        Шаблоны
ivan@ivan-ASUS:~$ cp -r fff Inf_Labs
ivan@ivan-ASUS:~$ cd Inf_Labs
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  fff  README.md
ivan@ivan-ASUS:~/Inf_Labs$ mv fff ~
mv: невозможно переместить 'fff' в '/home/ivan/fff': Каталог не пуст
ivan@ivan-ASUS:~/Inf_Labs$ mv fff /home/ivan
mv: невозможно переместить 'fff' в '/home/ivan/fff': Каталог не пуст
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  fff  README.md
ivan@ivan-ASUS:~/Inf_Labs$ cd ..
ivan@ivan-ASUS:~$ ls
 fff              snap        Загрузки      Общедоступные
 Inf_Labs         Видео       Изображения  'Рабочий стол'
 listing.tar.gz   Документы   Музыка        Шаблоны
ivan@ivan-ASUS:~$ cd Документы
ivan@ivan-ASUS:~/Документы$ cd ..
ivan@ivan-ASUS:~$ mv -r fff Inf_Labs
mv: неверный ключ — «r»
По команде «mv --help» можно получить дополнительную информацию.
ivan@ivan-ASUS:~$ ls
 fff              snap        Загрузки      Общедоступные
 Inf_Labs         Видео       Изображения  'Рабочий стол'
 listing.tar.gz   Документы   Музыка        Шаблоны
ivan@ivan-ASUS:~$ mv listing.tar.gz fff
ivan@ivan-ASUS:~$ cd fff
ivan@ivan-ASUS:~/fff$ ld
Команда «ld» не найдена, но может быть установлена с помощью:
sudo apt install binutils
ivan@ivan-ASUS:~/fff$ ls
listing.tar.gz
ivan@ivan-ASUS:~/fff$ cd ..
ivan@ivan-ASUS:~$ rm listing.tar.gz
rm: невозможно удалить 'listing.tar.gz': Нет такого файла или каталога
ivan@ivan-ASUS:~$ ld
Команда «ld» не найдена, но может быть установлена с помощью:
sudo apt install binutils
ivan@ivan-ASUS:~$ ls
 fff        snap    Документы   Изображения   Общедоступные   Шаблоны
 Inf_Labs   Видео   Загрузки    Музыка       'Рабочий стол'
ivan@ivan-ASUS:~$ cd fff
ivan@ivan-ASUS:~/fff$ ls
listing.tar.gz
ivan@ivan-ASUS:~/fff$ rm listing tar.gz
rm: невозможно удалить 'listing': Нет такого файла или каталога
rm: невозможно удалить 'tar.gz': Нет такого файла или каталога
ivan@ivan-ASUS:~/fff$ rm listing.tar.gz
ivan@ivan-ASUS:~/fff$ ld
Команда «ld» не найдена, но может быть установлена с помощью:
sudo apt install binutils
ivan@ivan-ASUS:~/fff$ ls
ivan@ivan-ASUS:~/fff$ cd ..
ivan@ivan-ASUS:~$ cd Inf_Labs
ivan@ivan-ASUS:~/Inf_Labs$ cat Read.me
cat: Read.me: Нет такого файла или каталога
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  fff  README.md
ivan@ivan-ASUS:~/Inf_Labs$ cat README.md
# Inf_Labsivan@ivan-ASUS:~/Inf_Labs$ ps
    PID TTY          TIME CMD
   4028 pts/1    00:00:00 bash
  40182 pts/1    00:00:00 ps
ivan@ivan-ASUS:~/Inf_Labs$ tail README.md
# Inf_Labsivan@ivan-ASUS:~/Inf_Labs$ head README.md
# Inf_Labsivan@ivan-ASUS:~/Inf_Labs$ grep I README.md
# Inf_Labs
ivan@ivan-ASUS:~/Inf_Labs$ history
    1  clear
    2  who
    3  pwd
    4  ls
    5  cp report.md Inf_labs
    6  cp fff Inf_labs
    7  ls
    8  cp -r fff Inf_Labs
    9  cd Inf_Labs
   10  ls
   11  mv fff ~
   12  mv fff /home/ivan
   13  ls
   14  cd ..
   15  ls
   16  cd Документы
   17  cd ..
   18  mv -r fff Inf_Labs
   19  ls
   20  mv listing.tar.gz fff
   21  cd fff
   22  ld
   23  ls
   24  cd ..
   25  rm listing.tar.gz
   26  ld
   27  ls
   28  cd fff
   29  ls
   30  rm listing tar.gz
   31  rm listing.tar.gz
   32  ld
   33  ls
   34  cd ..
   35  cd Inf_Labs
   36  cat Read.me
   37  ls
   38  cat README.md
   39  ps
   40  tail README.md
   41  head README.md
   42  grep I README.md
   43  history
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  fff  README.md
ivan@ivan-ASUS:~/Inf_Labs$ mkdir asd
ivan@ivan-ASUS:~/Inf_Labs$ rmdir asd
ivan@ivan-ASUS:~/Inf_Labs$ rmdir fff
rmdir: не удалось удалить 'fff': Каталог не пуст
ivan@ivan-ASUS:~/Inf_Labs$ rmdir -r fff
rmdir: неверный ключ — «r»
По команде «rmdir --help» можно получить дополнительную информацию.
ivan@ivan-ASUS:~/Inf_Labs$ rm -r fff
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  README.md
ivan@ivan-ASUS:~/Inf_Labs$ sudo su
[sudo] пароль для ivan: 
root@ivan-ASUS:/home/ivan/Inf_Labs# exit
exit
ivan@ivan-ASUS:~/Inf_Labs$ echo asd
asd
ivan@ivan-ASUS:~/Inf_Labs$ ssh-keygen
Generating public/private rsa key pair.
Enter file in which to save the key (/home/ivan/.ssh/id_rsa): Inf_Labs
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in Inf_Labs
Your public key has been saved in Inf_Labs.pub
The key fingerprint is:
SHA256:p/UbHseMeuVWhMa78ebLvVPvyRHb3BTlQYXY6OWerdI ivan@ivan-ASUS
The key's randomart image is:
+---[RSA 3072]----+
|             +.++|
|            o +.o|
|           . + o.|
|            . = o|
|        S o  o *.|
|         + . +*oO|
|        .   =++O*|
|           oo=E.B|
|          ..oo XB|
+----[SHA256]-----+
ivan@ivan-ASUS:~/Inf_Labs$ ssh-copy-id i_tatarkin@185.185.5.249.140
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed

/usr/bin/ssh-copy-id: ERROR: ssh: Could not resolve hostname 185.185.5.249.140: Name or service not known

ivan@ivan-ASUS:~/Inf_Labs$ ssh-copy-id i_tatarkin@185.5.249.140
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed

/usr/bin/ssh-copy-id: WARNING: All keys were skipped because they already exist on the remote system.
		(if you think this is a mistake, you may want to use -f option)

ivan@ivan-ASUS:~/Inf_Labs$ ssh i_tatarkin@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 25 11:49:11 2023 from 176.59.56.91
i_tatarkin@vds2476450:~$ ls
listing  listing.tar.gz
i_tatarkin@vds2476450:~$ rm listing
i_tatarkin@vds2476450:~$ rm listing.tar.gz
i_tatarkin@vds2476450:~$ ls
i_tatarkin@vds2476450:~$ cd ..
i_tatarkin@vds2476450:/home$ ls
a_bolotin     d_jgenti     f_lerner     m_hulagov      n_gavrilov   t_grigoriev
a_ganyak      d_kuleshov   i_tatarkin   mivallion      n_ivanov     v_frolov
a_pereverzev  d_nurgaliev  k_denisov    m_pinchuk      n_radion     v_romanov
a_popov       d_shirshov   k_ismailova  m_vlasko       n_soliviova
a_shiapov     e_fedorova   k_nikolskiy  m_yavmetdinov  n_stepanov
i_tatarkin@vds2476450:/home$ logout
Connection to 185.5.249.140 closed.
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  Inf_Labs.pub  README.md
ivan@ivan-ASUS:~/Inf_Labs$ rm Inf_Labs.pub
ivan@ivan-ASUS:~/Inf_Labs$ -czvf README.tar.gz README.md
-czvf: команда не найдена
ivan@ivan-ASUS:~/Inf_Labs$ tar -czvf README.tar.gz README.md
README.md
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  README.md  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ scp listing.tar.gz i _tatarkin@185.185.5.249.140
_tatarkin@185.185.5.249.140: No such file or directory
ivan@ivan-ASUS:~/Inf_Labs$ scp README.tar.gz i _tatarkin@185.185.5.249.140
_tatarkin@185.185.5.249.140: No such file or directory
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  README.md  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ scp README.tar.gz i _tatarkin@185.5.249.140
_tatarkin@185.5.249.140: No such file or directory
ivan@ivan-ASUS:~/Inf_Labs$ scp README.tar.gz i_tatarkin@185.5.249.140
ivan@ivan-ASUS:~/Inf_Labs$ ssh i_tatarkin@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Oct 15 12:30:31 2023 from 79.139.144.147
i_tatarkin@vds2476450:~$ ls
i_tatarkin@vds2476450:~$ ls
i_tatarkin@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  i_tatarkin@185.5.249.140  README.md  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ scp README.tar.gz i_tatarkin@185.5.249.140
ivan@ivan-ASUS:~/Inf_Labs$ ssh i_tatarkin@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Oct 15 12:36:40 2023 from 79.139.144.147
i_tatarkin@vds2476450:~$ ls
i_tatarkin@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
ivan@ivan-ASUS:~/Inf_Labs$ scp README.tar.gz i_tatarkin@185.5.249.140:~
README.tar.gz                                 100%  140    16.3KB/s   00:00    
ivan@ivan-ASUS:~/Inf_Labs$ ssh i_tatarkin@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Oct 15 12:39:40 2023 from 79.139.144.147
i_tatarkin@vds2476450:~$ ls
README.tar.gz
i_tatarkin@vds2476450:~$ tar -xzvf README.tar.gz
README.md
i_tatarkin@vds2476450:~$ scp i_tatarkini@ip:~/README.md ~ 
ssh: Could not resolve hostname ip: Temporary failure in name resolution
i_tatarkin@vds2476450:~$ scp i_tatarkin@185.5.249.140:~/README.md ~
i_tatarkin@185.5.249.140's password: 
Permission denied, please try again.
i_tatarkin@185.5.249.140's password: 
README.md                                     100%   10     8.1KB/s   00:00    
i_tatarkin@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  i_tatarkin@185.5.249.140  README.md  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ cd ..
ivan@ivan-ASUS:~$ ls
 fff        snap    Документы   Изображения   Общедоступные   Шаблоны
 Inf_Labs   Видео   Загрузки    Музыка       'Рабочий стол'
ivan@ivan-ASUS:~$ ssh i_tatarkin@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Oct 15 12:43:43 2023 from 79.139.144.147
i_tatarkin@vds2476450:~$ ls
README.md  README.tar.gz
i_tatarkin@vds2476450:~$ scp i_tatarkin@185.5.249.140:~/README.md ~/Inf_Labs
i_tatarkin@185.5.249.140's password: 
README.md                                     100%   10     3.1KB/s   00:00    
i_tatarkin@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
ivan@ivan-ASUS:~$ ls
 fff        snap    Документы   Изображения   Общедоступные   Шаблоны
 Inf_Labs   Видео   Загрузки    Музыка       'Рабочий стол'
ivan@ivan-ASUS:~$ cd Inf_Labs
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  i_tatarkin@185.5.249.140  README.md  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ rm README.md
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  i_tatarkin@185.5.249.140  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ ssh i_tatarkin@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Oct 15 12:50:32 2023 from 79.139.144.147
i_tatarkin@vds2476450:~$ scp i_tatarkin@185.5.249.140:~/README.md ~/Inf_Labs
i_tatarkin@185.5.249.140's password: 
README.md                                     100%   10     7.1KB/s   00:00    
i_tatarkin@vds2476450:~$ ls
Inf_Labs  README.md  README.tar.gz
i_tatarkin@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  i_tatarkin@185.5.249.140  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ rm i_tatarkin@185.5.249.140
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ ssh i_tatarkin@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Oct 15 12:51:34 2023 from 79.139.144.147
i_tatarkin@vds2476450:~$ ls
Inf_Labs  README.md  README.tar.gz
ls
> ls
> exit
> i_tatarkin@vds2476450:~$ ls
> kill
> ^C
i_tatarkin@vds2476450:~$ ды
Could not find command-not-found database. Run 'sudo apt update' to populate it.
ды: command not found
i_tatarkin@vds2476450:~$ ls
i_tatarkin@vds2476450:~$ scp i_tatarkin@185.5.249.140:~/README.md ~/"Рабочий стол"
i_tatarkin@185.5.249.140's password: 
README.md                                                                         100%   10     4.7KB/s   00:00    
i_tatarkin@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ cd ..
ivan@ivan-ASUS:~$ cd Рабочий стол
bash: cd: слишком много аргументов
ivan@ivan-ASUS:~$ ssh i_tatarkin@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Oct 15 12:52:46 2023 from 79.139.144.147
i_tatarkin@vds2476450:~$ ls
'�Рабо�'$'\207''ий �'$'\207''�'$'\201''�'$'\202''ол'   Inf_Labs   README.md   README.tar.gz
i_tatarkin@vds2476450:~$ rm ^C
i_tatarkin@vds2476450:~$ rm '�Рабо�'$'\207''ий �'$'\207''�'$'\201''�'$'\202''ол'
rm: cannot remove '�Рабо�'$'\207''ий �'$'\207''�'$'\201''�'$'\202''ол': No such file or directory
i_tatarkin@vds2476450:~$ ls
'�Рабо�'$'\207''ий �'$'\207''�'$'\201''�'$'\202''ол'   Inf_Labs   README.md   README.tar.gz
i_tatarkin@vds2476450:~$ rm "207''ий �'$'\207''�'$'\201''�'$'\2''ол'л''\202''ол'�'
rm: cannot remove '�Рабо�\ "207ий �'$'\207''�'$'\201''�'$'\202''ол': No such file or directory
i_tatarkin@vds2476450:~$ ls
'�Рабо�'$'\207''ий �'$'\207''�'$'\201''�'$'\202''ол'   Inf_Labs   README.md   README.tar.gz
i_tatarkin@vds2476450:~$ scp i_tatarkin@id:~/README.md ~/Inf_Labs
ssh: Could not resolve hostname id: Temporary failure in name resolution
i_tatarkin@vds2476450:~$ ls                                                 
'�Рабо�'$'\207''ий �'$'\207''�'$'\201''�'$'\202''ол'   Inf_Labs   README.md   README.tar.gz
i_tatarkin@vds2476450:~$ scp i_tatarkin@185.5.249.140:~/README.md ~/Inf_Labs
i_tatarkin@185.5.249.140's password: 
README.md                                                                         100%   10     7.2KB/s   00:00    
i_tatarkin@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
ivan@ivan-ASUS:~$ ls
 fff        snap    Документы   Изображения   Общедоступные   Шаблоны
 Inf_Labs   Видео   Загрузки    Музыка       'Рабочий стол'
ivan@ivan-ASUS:~$ cd Inf_Lab
bash: cd: Inf_Lab: Нет такого файла или каталога
ivan@ivan-ASUS:~$ cd Inf_Labs
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  Inf_Labs  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ cd Inf_Labs
bash: cd: Inf_Labs: Это не каталог
ivan@ivan-ASUS:~/Inf_Labs$ rm Inf_Labs
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ rm README.tar.gz
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab
ivan@ivan-ASUS:~/Inf_Labs$ ssh i_tatarkin@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Oct 15 13:00:45 2023 from 79.139.144.147
i_tatarkin@vds2476450:~$ ls
'�Рабо�'$'\207''ий �'$'\207''�'$'\201''�'$'\202''ол'   Inf_Labs   README.md   README.tar.gz
i_tatarkin@vds2476450:~$ scp i_tatarkin@185.5.249.140:~/README.md ~/Inf_Labs
i_tatarkin@185.5.249.140's password: 
README.md                                                                         100%   10    10.9KB/s   00:00    
i_tatarkin@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab
ivan@ivan-ASUS:~/Inf_Labs$ ssh i_tatarkin@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Sun Oct 15 13:18:25 2023 from 79.139.144.147
i_tatarkin@vds2476450:~$ rm '�Рабо�'$'\207''ий �'$'\207''�'$'\201''�'$'\202''ол'
Could not find command-not-found database. Run 'sudo apt update' to populate it.
�кrm: command not found
i_tatarkin@vds2476450:~$ ls
'�Рабо�'$'\207''ий �'$'\207''�'$'\201''�'$'\202''ол'   Inf_Labs   README.md   README.tar.gz
i_tatarkin@vds2476450:~$ scp i_tatarkin@185.5.249.140:~/README.md ~         
i_tatarkin@185.5.249.140's password: 
README.md                                                                         100%   10    10.2KB/s   00:00    
i_tatarkin@vds2476450:~$ ls
'�Рабо�'$'\207''ий �'$'\207''�'$'\201''�'$'\202''ол'   Inf_Labs   README.md   README.tar.gz
i_tatarkin@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
ivan@ivan-ASUS:~/Inf_Labs$ cd ..
ivan@ivan-ASUS:~$ ls
 fff        snap    Документы   Изображения   Общедоступные   Шаблоны
 Inf_Labs   Видео   Загрузки    Музыка       'Рабочий стол'
ivan@ivan-ASUS:~$ scp i_tatarkin@185.5.249.140:~/README.md ~ 
README.md                                                                         100%   10     1.3KB/s   00:00    
ivan@ivan-ASUS:~$ ls
 fff        README.md   Видео       Загрузки      Музыка         'Рабочий стол'
 Inf_Labs   snap        Документы   Изображения   Общедоступные   Шаблоны
ivan@ivan-ASUS:~$ 

```
7. **Замечания автора** отсутствуют
8. **Выводы**: В ходе выполнения лабораторной работы я познакомился с основными командами и операциями в терминале Linux. Эти знания могут быть полезными при работе с Linux-системами и автоматизации различных задач. Я также научился создавать и использовать SSH-ключи для безопасного доступа к удаленным серверам. Работа позволила мне лучше понять основы работы с командной строкой Linux и расширить свой навык взаимодействия с операционной системой через терминал.
