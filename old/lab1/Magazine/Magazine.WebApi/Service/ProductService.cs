using Magazine.Core.Model;
using Magazine.Core.Service;

namespace Magazine.WebApi.Service
{
    public class ProductService : IProductService<Product>
    {
        private readonly Dictionary<string, Product> _products = new() 
        {
            { "1" , new Product("1", "name1", "def1", 1, "path1") },
            { "2" , new Product("2", "name2", "def2", 2, "path2") },
            { "3" , new Product("3", "name3", "def3", 3, "path3") },
            { "4" , new Product("4", "name4", "def4", 4, "path4") },
        };

        public ProductService()
        {
        }

        public ProductService(List<Product> initialProducts)
        {
            foreach (var product in initialProducts)
            {
                _products.Add(product.Id, product);
            }
        }

        public void Add(Product item)
        {
            if(!_products.TryAdd(item.Id, item))
            {
                throw new Exception($"Cant't add '{item.Id}'. Item already in collection");
            }
            Console.WriteLine($"Product '{item.Id}' added");
        }

        public Product Edit(Product item)
        {
            if (!_products.ContainsKey(item.Id))
            {
                throw new Exception($"Cant't edit '{item.Id}'. Item not in collection");
            }
            Product source = _products[item.Id];
            source.Copy(item);
            return source;
        }

        public Product Remove(Product item)
        {
            if (!_products.ContainsKey(item.Id))
            {
                throw new Exception($"Cant't remove '{item.Id}'. Item not in collection");
            }
            Product deleted = _products[item.Id];
            _products.Remove(item.Id);
            return deleted;
        }

        public Product? Search(IServiceModel item)
        {
            if (!_products.ContainsKey(item.Id))
            {
                return null;
                // throw new Exception($"Cant't find '{item.Id}'. Item not in collection");
            }
            return _products[item.Id];
        }
    }
}
