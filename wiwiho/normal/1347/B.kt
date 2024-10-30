import java.util.*

val readQueue = ArrayDeque<String>()

fun getInput(): String {
    if (readQueue.isEmpty()) readLine()!!.split(' ', '\n').let { readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt() = getInput().toInt()
fun getDouble() = getInput().toDouble()
fun getString() = getInput()
fun getLong() = getInput().toLong()

fun <T> printv(v: Collection<T>) {
    v.forEachIndexed { i, t ->
        if (i != 0) print(" ")
        print(t)
    }
}

fun <T : Comparable<T>> lsort(v: MutableList<T>) {
    v.sort()
}

fun <T : Comparable<T>> gsort(v: MutableList<T>) {
    v.sortDescending()
}

fun <T, U> mp(t : T, u : U) = Pair(t, u)

typealias ll = Long
typealias pii = Pair<Int, Int>
typealias pll = Pair<ll, ll>

val MOD = 1000000007L
val MAX = 2147483647L

fun main() {

    val t = getInput().toInt()

    for(i in 1..t){
        val a1 = getInput().toInt()
        val b1 = getInput().toInt()
        val a2 = getInput().toInt()
        val b2 = getInput().toInt()

        var ans = false
        if(a1 == a2 && b1 + b2 == a1) ans = true
        if(a1 == b2 && b1 + a2 == a1) ans = true
        if(b1 == a2 && a1 + b2 == b1) ans = true
        if(b1 == b2 && a1 + a2 == b1) ans = true

        if(ans) println("Yes")
        else println("No")
    }

}