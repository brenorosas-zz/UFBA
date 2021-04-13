double round_robin(vector<int> &vet, int quantum)
{
    queue<int> fila;
    for (int &i : vet)
        fila.push(i);
    int time = 0;
    vector<int> ans;
    while (!fila.empty())
    {
        int x = fila.front();
        fila.pop();
        if (x <= quantum)
        {
            ans.push_back(time + x);
        }
        else
        {
            x -= quantum;
            fila.push(x);
        }
        time += quantum;
    }
    double sum = 0;
    int n = ans.size();
    for (int &i : ans)
    {
        sum += i;
    }
    return sum / n;
}
double escalonamento_prioridade(vector<int> &vet, vector<int> &priory, int quantum)
{
    priority_queue<tuple<int, int, int>> fila;
    int n = vet.size();
    int aux = 0;
    for (int i = 0; i < n; i++)
    {
        fila.push(make_tuple(priory[i], aux--, vet[i]));
    }
    vector<int> ans;
    int time = 0;
    while (!fila.empty())
    {
        tuple<int, int, int> x = fila.top();
        fila.pop();
        if (get<2>(x) <= quantum)
        {
            ans.push_back(get<2>(x) + time);
        }
        else
        {
            get<2>(x) -= quantum;
            get<1>(x) = aux--;
            fila.push(x);
        }
        time += quantum;
    }
    double sum = 0;
    for (int &i : ans)
    {
        sum += i;
    }
    return sum / n;
}