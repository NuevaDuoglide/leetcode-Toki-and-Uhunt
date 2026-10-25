from typing import List
import collections

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
            
        m = len(grid)       
        n = len(grid[0])    
        islands = 0
        
        # Iterasi seluruh kotak di dalam peta
        for i in range(m):
            for j in range(n):
                # Jika kita menemukan daratan baru
                if grid[i][j] == '1':
                    islands += 1
                    
                    # Tandai daratan ini sebagai air agar tidak terhitung dua kali
                    grid[i][j] = '0'
                    
                    # Gunakan BFS untuk menenggelamkan seluruh bagian pulau ini
                    queue = collections.deque([(i, j)])
                    
                    while queue:
                        r, c = queue.popleft()
                        
                        # Cek 4 arah yang bersebelahan: atas, bawah, kiri, kanan
                        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                            nr, nc = r + dr, c + dc
                            
                            # Jika tetangga berada dalam batas grid dan merupakan daratan ('1')[cite: 4, 5]
                            if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == '1':
                                # Langsung tenggelamkan saat dimasukkan ke antrean 
                                # untuk mencegah duplikasi di dalam antrean
                                grid[nr][nc] = '0'
                                queue.append((nr, nc))
                                
        return islands