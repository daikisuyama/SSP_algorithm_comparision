#C++の実行ファイルを実行(辺の重みは負を含む)
from subprocess import call
for i in ["spfa","bellmanford"]:
    for j in range(10):
        call([f"./{i}",f"m{j}.txt"])