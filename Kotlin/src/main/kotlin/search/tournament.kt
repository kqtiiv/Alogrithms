package search

fun <T : Comparable<T>> round(items: MutableList<T>): Pair<MutableList<T>, MutableList<T>> {
    val losers: MutableList<T> = mutableListOf()
    val winners: MutableList<T> = mutableListOf()
    while (items.size > 1) {
        var a = items.removeLast()
        var b = items.removeLast()
        if (a > b) {
            val temp = a
            a = b
            b = temp
        }
        losers.add(a)
        winners.add(b)
    }
    if (items.isNotEmpty()) {
        val a = items.removeLast()
        losers.add(a)
        winners.add(a)
    }
    return losers to winners
}

fun <T : Comparable<T>> boobyTournament(items: MutableList<T>): T =
    if (items.isNotEmpty()) {
        var items = items
        while (items.size > 1) {
            items = round(items).first
        }
        items.removeLast()
    } else {
        throw ArrayIndexOutOfBoundsException()
    }

fun <T : Comparable<T>> tournament(items: MutableList<T>): T =
    if (items.isNotEmpty()) {
        var items = items
        while (items.size > 1) {
            items = round(items).second
        }
        items.removeLast()
    } else {
        throw ArrayIndexOutOfBoundsException()
    }

fun <T : Comparable<T>> minAndMax(items: MutableList<T>): Pair<T, T> {
    val (losers, winners) = round(items)
    val least = boobyTournament(losers)
    val greatest = tournament(winners)
    return least to greatest
}

fun main() {
    val list: MutableList<Int> = mutableListOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    print(minAndMax(list))
}
