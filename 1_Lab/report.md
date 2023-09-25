# Отчет по лабораторной работе № 1
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Татаркин Иван Владимирович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Знакомство с Git, Github
2. **Цель работы**: Ознакомиться с основами системы контроля версий Git и платформой для хостинга репозиториев Github
3. **Задание**: 
 - завести репозиторий (**общий под все лабораторные работы с отдельной папкой под каждую лр!**)
- отчет с листингом в Markdown (листинг - ctrl+c -> ctrl+v из терминала с форматированием в markdown)
- создать отдельную ветку в репозитории под задание
- создать коммит с листингом и отчетом
- смержить ветку в мейн
4. **Идея, метод, алгоритм решения задачи**: 
- Завести репозиторий на Github
- Создать отдельную папку в репозитории под данную лабораторную работу.
- В папке создать файл отчета в формате Markdown.
- Создать отдельную ветку в репозитории для выполнения задания.
- В ветке создать коммит, включающий в себя листинг выполненных действий в терминале и отчет в Markdown.
- Смержить созданную ветку в ветку `main`
5. **Сценарий выполнения работы**:
- Создаем репозиторий на Github с названием "IvanTatarkin_LW"
- В репозитории создаем папку "LW_1" для данной лабораторной работы
- Внутри папки "LW_1" создаем файл отчета "report.md"
- Создаем отдельную ветку "rep_branch" для выполнения задания
- Внутри ветки "rep_branch" добавляем листинг выполненных команд в терминале в файл "report.md"
- Добавляем описание выполненной работы в файл "report.md".
- Создаем коммит с сообщением "Добавлен отчет по лабораторной работе №1"
- Смёрживаем ветку "lab1-branch" с веткой "main" с помощью Pull Request
6. **Протокол**: 
```bash
stud@ubuntu-aio:~$ sudo apt-get install git
[sudo] password for stud: 












Sorry, try again.
[sudo] password for stud: 
Sorry, try again.
[sudo] password for stud: 
sudo: 2 incorrect password attempts
stud@ubuntu-aio:~$ 
stud@ubuntu-aio:~$ git clone https://github.com/IvanTatarkin/IvanTatarkin_LW.git
Cloning into 'IvanTatarkin_LW'...
warning: You appear to have cloned an empty repository.
stud@ubuntu-aio:~$ ls
Desktop    Downloads  f3               Music     Public  Templates
Documents  f1         IvanTatarkin_LW  Pictures  snap    Videos
stud@ubuntu-aio:~$ cd IvanTatarkin_LW/
stud@ubuntu-aio:~/IvanTatarkin_LW$ git clone https://github.com/IvanTatarkin/IvanTatarkin_LW.git
Cloning into 'IvanTatarkin_LW'...
warning: You appear to have cloned an empty repository.
stud@ubuntu-aio:~/IvanTatarkin_LW$ cd IvanTatarkin_LW/
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ echo "# IvanTatarkin_LW" >> README.md
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ ls
README.md
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ cat > iayzn.txt
sksdkjfds
nfd
;kfdgd
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ ls
iayzn.txt  README.md
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git commit -m "first cmd"
Author identity unknown

*** Please tell me who you are.

Run

  git config --global user.email "you@example.com"
  git config --global user.name "Your Name"

to set your account's default identity.
Omit --global to set the identity only in this repository.

fatal: unable to auto-detect email address (got 'stud@ubuntu-aio.(none)')
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git config --global user.email "ivankrut9@yandex.ru"
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git config --global user.email "IvanTatarkin"
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git config --global user.email "ivankrut9@yandex.ru"
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git config --global user.name "IvanTatarkin"
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git config --global user.password "Rehcfrjdf1"
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git commit -m "first cmd"
On branch main

Initial commit

Untracked files:
  (use "git add <file>..." to include in what will be committed)
	README.md
	iayzn.txt

nothing added to commit but untracked files present (use "git add" to track)
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git add *
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git commit -m "first cmd"
[main (root-commit) b71e16b] first cmd
 2 files changed, 4 insertions(+)
 create mode 100644 README.md
 create mode 100644 iayzn.txt
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git push -u origin main
Username for 'https://github.com': ^[[A^[[A^C
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ 
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git branch -M main
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$  git remote add origin https://github.com/IvanTatarkin/IvanTatarkin_LW.git
error: remote origin already exists.
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ 
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git push -u origin main
Username for 'https://github.com': ^C
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git remote set-url origin https://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@github.com/IvanTatarkin/IvanTatarkin_LW
stud@ubuntu-aio:~/IvanTatarkin_LW/IvanTatarkin_LW$ git push -u origin main
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 16 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (4/4), 299 bytes | 299.00 KiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/IvanTatarkin/IvanTatarkin_LW
 * [new branch]      main -> main
Branch 'main' set up to track remote branch 'main' from 'origin'.
```
7. **Замечания автора** отсутствуют
8. **Выводы**: В результате выполнения лабораторной работы №1, я ознакомился с основами системы контроля версий Git и платформой Github. Эти навыки будут полезными в дальнейшем обучении и в профессиональной деятельности. Работа позволила понять, как эффективно организовывать и управлять проектами с использованием инструментов контроля версий и совместной разработки
