import java.util.*
import kotlin.math.*

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

fun <T> printv(v: Collection<T>) {
    v.forEachIndexed { i, t ->
        if (i != 0) print(" ")
        print(t)
    }
    println()
}

fun <T : Comparable<T>> lsort(v: MutableList<T>) {
    v.sort()
}

fun <T : Comparable<T>> gsort(v: MutableList<T>) {
    v.sortDescending()
}

fun <T, U> mp(t: T, u: U) = Pair(t, u)

fun ifloor(a: Long, b: Long): Long {
    if (b < 0) return ifloor(-a, -b)
    return if (a xor b > 0) a / b else (a - b + 1) / b
}

fun iceil(a: Long, b: Long): Long {
    if (b < 0) return iceil(-a, -b)
    return if (a xor b > 0) (a + b - 1) / b else a / b
}

fun ifloor(a: Int, b: Int) = ifloor(a.toLong(), b.toLong()).toInt()
fun iceil(a: Int, b: Int) = iceil(a.toLong(), b.toLong()).toInt()

typealias ll = Long
typealias pii = Pair<Int, Int>
typealias pll = Pair<ll, ll>

val MOD = 1000000007L
val MAX = 2147483647L

fun <T> List<T>.binarySearchWith(condition: (T) -> Boolean): Int {
    return binarySearch {
        if (condition(it)) 1
        else -1
    }.let { -(it + 1) }
}

fun List<Int>.lowerBound(i: Int): Int {
    return binarySearchWith { it >= i }
}

fun List<Int>.upperBound(i: Int): Int {
    return binarySearchWith { it > i }
}

var BIT = mutableListOf<Int>()

fun lowbit(x: Int): Int {
    return x and -x
}

fun modify(tx: Int, v: Int) {
    var x = tx
    while (x < BIT.size) {
        BIT[x] = max(BIT[x], v)
        x += lowbit(x)
    }
}

fun query(tx: Int): Int {
    var x = tx
    var ans = 0
    while (x > 0) {
        ans = max(ans, BIT[x])
        x -= lowbit(x)
    }
    return ans
}

fun main() {

    var T = readInt()
    while(T-- > 0) {

        val n = readInt()
        val a = readIntArray(n)

        BIT = MutableList(n + 1) { 0 }

        val pos = MutableList(n + 1) {mutableListOf<Int>()}
        for (i in 0 until n) {
            pos[a[i]].add(i + 1)
        }

        val v = mutableListOf<pii>()
        for (i in 1..n) {
            if (pos[i].size == 2) {
                v.add(mp(pos[i][0], pos[i][1]))
            }
        }
        v.sortByDescending {it.first}

        for (i in v) {
            var tmp = if (i.first + 1 < i.second) 3 else 2
            tmp = max(tmp, query(i.second) + 2)
            modify(i.second, tmp)
        }
        println(max(query(n), 1))

    }

}