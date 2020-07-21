#C++の実行ファイルを実行(辺の重みは非負)
from subprocess import call
for i in ["spfa","dijkstra","bellmanford"]:
    for j in range(10):
        call([f"./{i}",f"{j}.txt"])