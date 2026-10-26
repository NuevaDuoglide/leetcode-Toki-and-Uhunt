class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        
        # Inisialisasi dua variabel untuk menyimpan jumlah cara untuk 1 dan 2 langkah
        first = 1  # Jumlah cara untuk 1 langkah
        second = 2 # Jumlah cara untuk 2 langkah
        
        # Iterasi dari langkah ke-3 hingga langkah ke-n
        for i in range(3, n + 1):
            current = first + second  # Jumlah cara untuk langkah saat ini adalah jumlah cara untuk dua langkah sebelumnya
            first = second            # Geser first ke second
            second = current          # Geser second ke current
            
        return second  # Setelah loop, second akan berisi jumlah cara untuk n la