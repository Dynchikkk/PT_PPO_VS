using Magazine.Core.Model;
using Magazine.WebApi.Service;
using Microsoft.AspNetCore.Mvc;

namespace Magazine.WebApi.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class ProductServiceController : ControllerBase
    {
        private readonly ILogger<ProductServiceController> _logger;
        private readonly ProductService _productService = new();

        public ProductServiceController(ILogger<ProductServiceController> logger)
        {
            _logger = logger;
        }

        [HttpPost(Name = "AddProduct")]
        public void Add(string id, string name, string definition, int price, string img)
        {
            _productService.Add(new Product(id, name, definition, price, img));
        }

        [HttpPut(Name = "EditProduct")]
        public Product Edit(string id, string name, string definition, int price, string img)
        {
            return _productService.Edit(new Product(id, name, definition, price, img));
        }

        [HttpGet(Name = "GetProduct")]
        public Product Get(string id)
        {
            return _productService.Search(new Product(id, "", "", 0, ""));
        }

        [HttpDelete(Name = "RemoveProduct")]
        public Product Remove(string id)
        {
            return _productService.Remove(new Product(id, "", "", 0, ""));
        }
    }
}
