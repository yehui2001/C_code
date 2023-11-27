struct node{
    int x,y;
};



char map[25][25];
int vis[25][25];
int n,m,sx,sy,ans;
int dir[4][2]= {1,0,-1,0,0,1,0,-1};
  
int check(int x,int y){
     if(x<0 || y<0 || x>=m || y>=n)
        return 1;
     if(vis[x][y] || map[x][y] == '#')
        return 1;
    return 0;
}

void bfs(){
    int i;
    queue<node> Q;
    node a,next;
    ans = 0;
    a.x = sx;
    a.y = sy;
    vis[sx][sy] = 1;
    Q.push(a);
    while(!Q.empty())
    {
        ans++;
        a = Q.front();
        Q.pop();
        for(i = 0; i<4; i++)
        {
            next = a;
            next.x+=dir[i][0];
            next.y+=dir[i][1];
            if(check(next.x,next.y))
                continue;
            vis[next.x][next.y] = 1;
            Q.push(next);
        }
    }
}

void dfs(int x,int y){
for(int i=0;i<4;i++)
    {
        int nx=x+f[i];
        int ny=y+g[i];
        if(mp[nx][ny]=='.'&&vis[nx][ny]&&nx>0&&nx<=h&&ny>0&&ny<=w)
        {
            vis[nx][ny]=0;sum++;//也可在主函数里遍历找vis=0的个数 
            dfs(nx,ny);
            //vis[nx][ny]=1;常规回溯，但本题不需要 
        }
    }
}