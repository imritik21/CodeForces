
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    int n;
    cin>>n;
    int arr[n][n];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for (int row = 0; row < n; row++) {
        int x = row, y = 0;
        while (x < n && y < n) {
            cout << arr[x][y] << " ";
            x++;
            y++;
        }
        cout << endl;
    }
    for (int col = 1; col < n; col++) {
        int x = 0, y = col;
        while (x < n && y < n) {
            cout << arr[x][y] << " ";
            x++;
            y++;