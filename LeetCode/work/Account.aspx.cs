using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class work_Account : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
        {
            Response.Redirect("jiemian.aspx");
        }

        string ConStr1 = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con1 = new SqlConnection(ConStr1);
        string SqlStr1 = "select * from yhdl";   //要执行的sql语句
        SqlDataAdapter ada1 = new SqlDataAdapter(SqlStr1, con1);
        con1.Open();
        DataSet ds1 = new DataSet();
        ada1.Fill(ds1);

        GridView1.DataSource = ds1;
        GridView1.DataBind();

        /*if (!IsPostBack)
        {
            num.Text = "1";
            repdatabind();
        }*/
    }

   /* public void repdatabind()
    {
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr);
        string SqlStr;
        SqlStr = "select * from yhdl where 1=1 order by id asc"; //根据id的值按升序排序
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
        con.Open();             //打开连接
        DataSet ds = new DataSet();

        ada.Fill(ds, "dz");   //dz：表的名字
        PagedDataSource pds = new PagedDataSource();
        pds.DataSource = ds.Tables["dz"].DefaultView;   //DefaultView:相当于一个数据库中的视图
        pds.AllowPaging = true;     //允许分页
        pds.PageSize = 3;   //单页显示项数

        int curpage = Convert.ToInt32(num.Text);
        this.BtnDown.Enabled = true;    //下一页功能可用
        this.BtnUp.Enabled = true;      //上一页功能可用
        pds.CurrentPageIndex = curpage - 1;     //当前页
        if (curpage == 1)   //第一页时 上一页按钮不可用
        {
            this.BtnUp.Enabled = false;
        }
        if (curpage == pds.PageCount)   //最后一页时 下一页按钮不可用
        {
            this.BtnDown.Enabled = false;
        }
        this.Repeater1.DataSource = pds;
        this.Repeater1.DataBind();
    }

    protected void BtnUp_Click(object sender, EventArgs e)
    {
        this.num.Text = Convert.ToString(Convert.ToInt32(num.Text) - 1);
        repdatabind();
    }

    protected void BtnDown_Click(object sender, EventArgs e)
    {
        this.num.Text = Convert.ToString(Convert.ToInt32(num.Text) + 1);
        repdatabind();
    }*/

    protected void GridView1_PageIndexChanging(object sender, GridViewPageEventArgs e)

    {

        GridView1.PageIndex = e.NewPageIndex;

        GridView1.DataBind();

    }
}