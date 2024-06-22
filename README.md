В первой части отдельным консольным приложением реализуем основную функцию –  вычисление размера, в зависимости от стратегии

Общий принцип работы следующий: пользователь указывает директорию, для которой требуется вычислить размер содержимого.
Функция, в зависимости от выбранной стратегии, проводит вычисление, где результатом является набор соответствующих данных, вида

список файлов и папок (только верхнего уровня) / список типов файлов, содержащихся в директории, а также занимаемый ими объём в процентах (точность два знака после запятой; если точности не хватает, а размер элемента не равен нулю, требуется это показать - например, в виде "< 0.01%").

Основная цель – проработка всевозможных условий. С целью доказательства того факта, что всевозможные условия обработаны, требуется подготовить тесты (примеры), на которых будете демонстрировать состоятельность вашей функции.


Часть №2

Во второй части требуется реализовать приложение с графическим интерфейсом.

Требуется изучить концепцию MVC и её реализацию в Qt.

Требуется разработать модель, данные в которой будут заполняться с помощью реализованных ранее стратегий обхода содержимого папки.

Модель должна содержать,  название и занимаемый объём в процентах. 
В примере используется модель файловой системы (QFileSystemModel), отображаемая в двух представлениях: QTreeView (слева) и QTableView (справа).

После реализации вашей модели, достаточно просто сменить тип отображаемой модели у QTableView.

Таким образом, пользователь, выбрав директорию в левой части окна, тем самым запускает процесс её сканирования и может увидеть содержимое директории (относительно заданного типа группировки) в правой части окна.

Соответственно, также требуется доработать графический интерфейс, позволив пользователю выбирать способ группировки содержимого.
