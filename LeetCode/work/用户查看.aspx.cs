using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class work_用户查看 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
        {
            Response.Redirect("jiemian.aspx");
        }
        if (!IsPostBack)
        {
            int did = Convert.ToInt32(Request["id"]);
            int id = did;
            string neirong = TextBox1.Text.ToString();  //要插入纸条的内容
            string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";

            SqlConnection con1 = new SqlConnection(ConStr);
            string SqlStr = "select * from yhdl where id='" + id + "'";   //要执行的sql语句
            SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con1);
            con1.Open();
            DataSet ds = new DataSet();
            ada.Fill(ds);
            username.Text = ds.Tables[0].Rows[0][1].ToString();

            num.Text = "1";
            repdatabind();
        }
    }

    public void repdatabind()
    {
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr);
        string SqlStr;
        SqlStr = "select * from dianzan where 1 = 1 order by redu desc";  //根据id的值按升序排序
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
        con.Open();             //打开连接
        DataSet ds = new DataSet();
        ada.Fill(ds);

        int did = Convert.ToInt32(Request["id"]);
        DataTable yh = new DataTable(); //创建新表

        for (int i = 0; i < ds.Tables[0].Columns.Count; i++)
        {
            yh.Columns.Add(ds.Tables[0].Columns[i].ColumnName);//有重载的方法，可以加入列数据的类型
        }
        for (int i = 0; i < ds.Tables[0].Rows.Count; i++)
        {
            int id = Convert.ToInt32(ds.Tables[0].Rows[i][0]);
            if (id != did)
            {
                yh.ImportRow(ds.Tables[0].Rows[i]);       //将新行添加到yh中
            }
        }
        ds.Tables.Add(yh);

        PagedDataSource pds = new PagedDataSource();
        pds.DataSource = ds.Tables[1].DefaultView;
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
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        int did = Convert.ToInt32(Request["id"]);
        Response.Redirect("用户管理.aspx?id=" + did);
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        int did = Convert.ToInt32(Request["id"]);
        int id = did;
        string neirong = TextBox1.Text.ToString();  //要插入纸条的内容
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";

        SqlConnection con1 = new SqlConnection(ConStr);
        string SqlStr = "select * from yhdl where id='" + id + "'";   //要执行的sql语句
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con1);
        con1.Open();
        DataSet ds = new DataSet();
        ada.Fill(ds);
        string username = ds.Tables[0].Rows[0][1].ToString();
        con1.Close();
        con1.Dispose();

        SqlConnection con = new SqlConnection(ConStr);
        con.Open();
        string zfuser = " ";
        int redu = 0;    //初始化热度值
        string sqlcr = "INSERT INTO dianzan VALUES( '" + id + "','" + neirong + "','" + redu + "','" + username + "','" + zfuser + "')";    //INSERT语句插入
        SqlCommand myCom = new SqlCommand(sqlcr, con);   //定义SqlCommand对象实例
        myCom.ExecuteNonQuery();     //执行插入语句
        ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('成功发布留言!');</script>");
        con.Close();
        con.Dispose();
        Response.Redirect("用户管理.aspx?id=" + did);
    }

    protected void Repeater1_ItemDataBound(object sender, RepeaterItemEventArgs e)
    {
        //Button p = (Button)Repeater1.Items[id0].FindControl("Button3");
        Button q = (Button)e.Item.FindControl("Button3");
        int p = Convert.ToInt32(q.CommandArgument);
        //判断里层repeater处于外层repeater的哪个位置（ AlternatingItemTemplate，FooterTemplate，
        //HeaderTemplate，，ItemTemplate，SeparatorTemplate）
        if (e.Item.ItemType == ListItemType.Item || e.Item.ItemType == ListItemType.AlternatingItem)
        {
            Repeater rep = e.Item.FindControl("Repeater2") as Repeater;//找到里层的repeater对象
            DataRowView rowv = (DataRowView)e.Item.DataItem;//找到分类Repeater关联的数据项 
            //int typeid = Convert.ToInt32(rowv["qtid"]); //获取填充子类的id 

            string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
            SqlConnection con = new SqlConnection(ConStr);
            string SqlStr;
            SqlStr = "select top 10 * from pinglun where neirong='" + p + "'";
            SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
            con.Open();             //打开连接
            DataSet ds = new DataSet();
            ada.Fill(ds);
            rep.DataSource = ds;
            rep.DataBind();
        }
    }

    protected void Repeater1_ItemCommand(object source, RepeaterCommandEventArgs e)
    {
        int cnt = Convert.ToInt32(e.CommandArgument);
        //string neirong = e.CommandArgument.ToString();
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr);
        string SqlStr = "select * from dianzan where cnt='" + cnt + "'";   //要执行的sql语句
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
        con.Open();
        DataSet ds = new DataSet();
        ada.Fill(ds);
        if (e.CommandName == "add")
        {
            int redu = Convert.ToInt32(ds.Tables[0].Rows[0][2]) + 1;    //获取第一张表中第一行第二列
            string sqlxg = "update dianzan set redu='" + redu + "' where cnt='" + cnt + "'";
            SqlCommand myCom = new SqlCommand(sqlxg, con);   //定义SqlCommand对象实例
            myCom.ExecuteNonQuery();     //执行插入语句
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('成功 +1');</script>");
            con.Close();
            con.Dispose();
            int did = Convert.ToInt32(Request["id"]);
            Response.Redirect("用户查看.aspx?id=" + did);
        }
        else if (e.CommandName == "pinglun")
        {
            int did = Convert.ToInt32(Request["id"]);
            string ConStr1 = "server=(local);user id=cjn;pwd=123;database=cs";
            SqlConnection con1 = new SqlConnection(ConStr1);
            string SqlStr1 = "select * from yhdl where id='" + did + "'";   //要执行的sql语句
            SqlDataAdapter ada1 = new SqlDataAdapter(SqlStr1, con1);
            con1.Open();
            DataSet ds1 = new DataSet();
            ada1.Fill(ds1);

            //ds1表中的数据
            string m2 = ds1.Tables[0].Rows[0][1].ToString(); //评论者用户名

            TextBox bbb = (TextBox)e.Item.FindControl("TextBox2");
            string pl = bbb.Text.ToString();
            SqlConnection con2 = new SqlConnection(ConStr);
            con2.Open();
            string sqlcr = "INSERT INTO pinglun VALUES( '" + pl + "','" + m2 + "','" + cnt + "')";    //INSERT语句插入
            SqlCommand myCom = new SqlCommand(sqlcr, con2);   //定义SqlCommand对象实例
            myCom.ExecuteNonQuery();     //执行插入语句
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('评论成功!');</script>");
            con2.Close();
            con2.Dispose();
            Response.Redirect("用户查看.aspx?id=" + did);
        }
        else if (e.CommandName == "zhuanfa")
        {

            int did = Convert.ToInt32(Request["id"]);
            int id = did;
            string ConStr1 = "server=(local);user id=cjn;pwd=123;database=cs";

            SqlConnection con2 = new SqlConnection(ConStr);
            string SqlStr2 = "select * from yhdl where id='" + id + "'";   //要执行的sql语句
            SqlDataAdapter ada2 = new SqlDataAdapter(SqlStr2, con2);
            con2.Open();
            DataSet ds2 = new DataSet();
            ada2.Fill(ds2);
            string username = ds2.Tables[0].Rows[0][1].ToString();
            con2.Close();
            con2.Dispose();

            string neirong = ds.Tables[0].Rows[0][1].ToString();  //要插入纸条的内容
            SqlConnection con1 = new SqlConnection(ConStr1);
            con1.Open();
            int redu = 0;    //初始化热度值
            string zfuser = "转自：" + ds.Tables[0].Rows[0][3].ToString();
            string sqlcr = "INSERT INTO dianzan VALUES( '" + id + "','" + neirong + "','" + redu + "','" + username + "','" + zfuser + "')";    //INSERT语句插入
            SqlCommand myCom = new SqlCommand(sqlcr, con1);   //定义SqlCommand对象实例
            myCom.ExecuteNonQuery();     //执行插入语句
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('转发成功!');</script>");
            con1.Close();
            con1.Dispose();
            Response.Redirect("用户管理.aspx?id=" + did);
        }
    }
}