using Magazine.Core.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Magazine.Core.Service
{
    public interface IProductService<T>
        where T : class, IServiceModel
    {
        void Add(T item);
        T Remove(T item);
        T Edit(T item);
        T? Search(IServiceModel item);
    }
}
