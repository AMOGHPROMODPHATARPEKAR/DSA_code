if(s.empty())
        {
            s.push(data);
            mini = data;
        }
        else{
            if(data<mini)
            {
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }