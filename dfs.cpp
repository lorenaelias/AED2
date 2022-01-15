#include "stack"

static int cnt, pre[1000];

void GRAPHdfs(Grafo G) {
   STACKinit( G->V);
   cnt = 0;
   for (vertex v = 0; v < G->V; ++v)
        pre[v] = -1;

   for (vertex v = 0; v < G->V; ++v)
        if (pre[v] == -1)
            dfs( G, v);
}

void dfs( Graph G, vertex v) {
   pre[v] = cnt++;
   STACKpush( v);

   while (!STACKempty( )) {
      v = STACKpop( );

      for (vertex w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1)
            if (pre[w] == -1) {
               pre[w] = cnt++;
               STACKpush( w);
            }
   }
}
