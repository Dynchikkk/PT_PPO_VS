using Microsoft.AspNetCore.Mvc;

namespace Magazine.WebApi.Controllers
{
    public class HomeController : Controller
    {
        public string Index()
        {
            return "Made by D. Belyaev and M. Demin";
        }
    }
}
