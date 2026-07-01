package other

fun exp(
    m: Int,
    n: Int,
): Int =
    when {
        n == 0 -> 1
        n and 1 == 0 -> exp(m * m, n / 2)
        else -> m * exp(m * m, (n - 1) / 2)
    }
