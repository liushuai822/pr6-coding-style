# ПР6. Соглашения о кодировании и обзор кода в репозитории

Репозиторий на GitHub: <https://github.com/liushuai822/pr6-coding-style> (ветвь `main`).

Тот же код с прежней историей публиковался в ветви `style/complex` репозитория <https://github.com/liushuai822/asu-tp-lab>.

Каталог `repo` — локальная копия репозитория (ветвь `style/complex`).

## История

| Коммит | Сообщение |
|---|---|
| f4f4f7c | исходное состояние (<A>) |
| 021d56a | style: normalize encoding |
| b47805d | style: fix line length and layout |
| d23ce8a | style: rename members and fix header guard |
| 5004e5a | refactor: make interface explicit and const-correct |
| 8fcb002 | fix: safe input |

## Как воспроизвести проверки

```
cd repo
git ls-files --eol                     # 1: кодировка и переводы строк
git diff --check f4f4f7c..8fcb002      # 2: пусто = нарушений пробелов нет

g++ -std=c++17 -Wall -Wextra -Werror testcmp.cpp mycomplex.cpp -o app
printf '1 2 x\n' | ./app > after.txt   # 3: сравнить с before.txt исходного коммита

g++ -std=c++17 -Wall -Wextra check_const.cpp mycomplex.cpp -o check_const   # 4
g++ -std=c++17 -Wall -Wextra check_compare.cpp mycomplex.cpp -o check_compare

awk 'BEGIN { s = ""; for (i = 0; i < 400; i++) s = s "x"; print "1 2 " s }' > long.txt
./app < long.txt                       # 5: не должно падать
```

Компилятор, которым сняты выводы в отчёте: g++ (GCC) 16.2.0 (w64devkit 2.11.0).
Файлы check_const.cpp и check_compare.cpp создаются вручную (в задании они не выдаются).

## Отчёт

`../ПР6-Кодирование-отчет.docx` и `.pdf` — 14 страниц.