using Microsoft.EntityFrameworkCore.Metadata;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Magazine.Core.Model
{
    public class Product : IServiceModel
    {
        public string Id { get; }

        public string Name { get; private set; }
        public string Definition { get; private set; }
        public float Price { get; private set; }
        public string Image { get; private set; }

        public Product(string name, string definition, float price, string image)
        {
            Id = Guid.NewGuid().ToString();

            Name = name;
            Definition = definition;
            Price = price;
            Image = image;
        }

        public Product(string id, string name, string definition, float price, string image)
        {
            Id = id;

            Name = name;
            Definition = definition;
            Price = price;
            Image = image;
        }

        public void Copy(Product reference)
        {
            Name = reference.Name;
            Definition = reference.Definition;
            Price = reference.Price;
            Image = reference.Image;
        }
    }
}
