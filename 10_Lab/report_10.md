# Отчет по лабораторной работе № 10
## по курсу "Фундаментальная информатика"

Студент группы М80-108Б-23 Татаркин Иван Владимирович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Издательская система Tex
2. **Цель работы**: Ознакомиться с работой в издательской системе Tex
3. **Задание**:
- Сверстать в Tex заданные согласно варианту страницы книг по информатике и математике
4. **Идея, метод, алгоритм решения задачи**: Прорабатываем материал в Texstudio
5. **Сценарий выполнения работы**: Задаём нужные нам библиотеки в начале файла, переписываем текст - используем структуры для математических формул, заканчиваем строчку в необходимых местах, обозначаем абзацы. Графики строим в сторонем приложении и вставляем в работу.
6. **Протокол**:
```
\documentclass[12pt, a4paper]{article}
\usepackage[T2A]{fontenc}
\usepackage[utf8]{inputenc}
\usepackage[english,russian]{babel}
\usepackage{indentfirst}
\usepackage{amssymb}
\begin{document}
Из равенств\space\space $C^{0}_{n} = C^{n}_{n} = 1$\space\space и формулы\space\space (1.19) следует, что в\\
$n$-й строчке этой таблицы стоят числа\\
\[1, C^{1}_{n},..., C^{k}_{n}, ..., C^{n-1}_{n}, 1.\]
\textbf{1.5 Логические символы}\\
В\space\space математических\space\space рассуждениях\space\space\space часто\space\space встречаются\space\space выра-\\
жения\space\space\space\space\space<<существует элемент>>,\space\space\space\space\space обладающий\space\space\space\spaceнекоторыми\\
свойствами,\space\space и \space\space<<любой элемент>>\space\space\space среди элементов,\space\space имеющих\\
некоторое \space\spaceсвойство. Вместо\space\space слова \space\space<<существует>>\space\space или равно-\\
сильного\space\space ему\space\space слова\space\space <<найдётся>>\space\space иногда пишут символ $\exists$, т. е.\\
перевернутую\space\space латинскую\space\space букву\space\space E\space\space (от\space\space англ.\space\space Existence --- су-\\
ществование),\space\space а\space\space вместо слов <<любой>>, <<каждый>>, <<всякий>> ---\\
символ\space\space $\forall$,\space\space т. е. перевернутое латинское A (от англ. Any --- лю-\\
бой).\space\space Символ\space\space $\exists$ называется\space\space символом\space\space \textit{существования}, a сим-\\
вол $\forall$ --- символом \textit{всеобщности}.\\
\par
\textbf{П р и м е р ы. 1.} Определение\space\space объединения\space\space $\bigcup\limits_{\alpha\in\mathfrak{A}} A_{\alpha}$\space\space мно-\\
жеств\space\space $A_{a}, a \in\mathfrak{A}$,\space\space записывается\space\space с\space\space помощью\space логического\space симв-\\
ола существования следующим образом:\\
\[\bigcup\limits_{\alpha\in\mathfrak{A}} A_{\alpha} = \{x : \exists    \alpha \in\mathfrak{U}, x \in A_{\alpha}\},  \]
а\space\space\space определение\space\space\space пересечения\space\space $\bigcup\limits_{\alpha\in\mathfrak{A}} A_{\alpha}$,\space\space записанное\space\space с\space\space помощью\\
символа всеообщности, имеет вид\\
\[\bigcup\limits_{\alpha\in\mathfrak{A}} A_{\alpha} = \{x : \forall    \alpha \in\mathfrak{A}, x \in A_{\alpha}\}.  \]
\par
\textbf{2.} Пусть\space\space \textbf{R}\space --- \space\spaceмножество \space\spaceдействительных чисел \spaceи\space\space пусть\\
задана\space\space\space функция\space\space $f : \textbf{R} \to \textbf{R}$\space\space т. е.\space\space функция,\space\space определенная\space\space на\\
множестве\space\space\space действительных\space\space\space чисел\space\space и\space\space принимающая\space\space действи-\\
тельные\space\space значения.\space\space Функция\space\space\space $f$ \space\spaceназывается\space\space \textit{четной\space\space функци-\\
ей},\space\space если\space\space для\space\space любого\space\space $x \in R$\space\space выполняется\space\space равенство\space\space\space $f(-x)=\\
=f(x)$.\space\space\space Используя\space\space логическую\space\space символику,\space\space это\space\space условие\space\space мож-\\
но записать короче:
\[\forall x \in \textit{R} : f(-x) = f(x).\]
\par
\textbf{3.} Функция\space\space $f : \textbf{R} \to \textbf{R}$\space\space называется\space\space периодической, если\space\space су-\\
ществует такое число $T>0$, что, каково бы ни было $x\in\textbf{R}$, спра-\\
\begin{center}
    \rule{2cm}{0.5pt}
\end{center}
\setcounter{page}{33}

\end{document} 
```
7. **Замечания автора** : -
8. **Выводы**: Мне понравилась работать в LaTeX так как это простой и эффективный способ вёрстки текстовых документов, который предлагает широкие возможности для создания качественных работ.
